#include <bits/stdc++.h>
using namespace std;
int freq[10];
int numOfDigits;
long long factorial[20];
void fact() {
  factorial[0] = 1;
  factorial[1] = 1;
  for (long long i = 2; i <= 19; i++) {
    factorial[i] = factorial[i - 1] * i;
  }
}
long long dfs(int r, int soFar[]) {
  if (r >= 10) {
    int numOfDigits = 0;
    for (int i = 0; i < 10; i++) {
      numOfDigits += soFar[i];
    }
    long long temp = factorial[numOfDigits];
    for (int i = 0; i < 10; i++) {
      temp = temp / factorial[soFar[i]];
    }
    if (soFar[0] != 0) {
      long long minus = factorial[numOfDigits - 1];
      minus = minus / factorial[soFar[0] - 1];
      for (int i = 1; i < 10; i++) {
        minus = minus / factorial[soFar[i]];
      }
      temp -= minus;
    }
    return temp;
  }
  long long temp = 0;
  if (freq[r] == 0) return dfs(r + 1, soFar);
  for (int i = 1; i <= freq[r]; i++) {
    soFar[r] = i;
    temp += dfs(r + 1, soFar);
    soFar[r] = 0;
  }
  return temp;
}
int main() {
  long long n;
  cin >> n;
  fact();
  while (n) {
    numOfDigits++;
    freq[n % 10] += 1;
    n = n / 10;
  }
  int vec[10];
  memset(vec, 0, sizeof(vec));
  cout << dfs(0, vec) << endl;
  return 0;
}
