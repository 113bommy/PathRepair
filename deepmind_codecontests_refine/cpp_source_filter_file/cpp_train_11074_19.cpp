#include <bits/stdc++.h>
using namespace std;
vector<int> getPrimeNumbers(int UPPER) {
  list<int> primeNumbers;
  for (int i = 2; i < UPPER; i++) {
    primeNumbers.push_back(i);
  }
  for (list<int>::iterator it = primeNumbers.begin(); it != primeNumbers.end();
       ++it) {
    list<int>::iterator it1 = it;
    it1++;
    while (it1 != primeNumbers.end()) {
      if (*it1 % *it == 0)
        it1 = primeNumbers.erase(it1);
      else
        it1++;
    }
  }
  vector<int> primes;
  for (list<int>::iterator it = primeNumbers.begin(); it != primeNumbers.end();
       ++it) {
    primes.push_back(*it);
  }
  return primes;
}
int main() {
  int N, M;
  cin >> N >> M;
  int UPPER = 1e5 + 7;
  vector<int> primeNumbers = getPrimeNumbers(UPPER);
  vector<int> stepsVector(UPPER, 0);
  int j = 0;
  for (int i = 1; i < 1e5; i++) {
    for (; j < primeNumbers.size(); j++) {
      if (primeNumbers[j] >= i) {
        stepsVector[i] = primeNumbers[j] - i;
        break;
      }
    }
  }
  vector<vector<int>> matr(N, (vector<int>(M, 0)));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int cinNum;
      cin >> cinNum;
      matr[i][j] = stepsVector[cinNum];
    }
  }
  int rowSteps = UPPER, colSteps = UPPER;
  for (int i = 0; i < N; i++) {
    int maxNum = 0;
    for (int j = 0; j < M; j++) {
      maxNum += matr[i][j];
    }
    rowSteps = min(maxNum, rowSteps);
  }
  for (int j = 0; j < M; j++) {
    int maxNum = 0;
    for (int i = 0; i < N; i++) {
      maxNum += matr[i][j];
    }
    colSteps = min(maxNum, colSteps);
  }
  cout << min(rowSteps, colSteps) << endl;
}
