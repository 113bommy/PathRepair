#include <bits/stdc++.h>
using namespace std;
template <typename T>
void printvec(vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int prime[1000001];
  for (int i = 2; i <= 1000000; i++) {
    prime[i] = i;
  }
  prime[0] = -1;
  prime[1] = -1;
  for (int p = 2; p <= 1000000; p++) {
    if (prime[p] == p) {
      for (int i = p * 2; i <= 1000000; i += p) prime[i] = p;
    }
  }
  long long int x;
  cin >> x;
  set<int> possible;
  int i;
  long long int mini1 = INT_MAX;
  for (i = 1; i * i < x; i++) {
    if (x % i == 0) {
      if (prime[i] == i) {
        if (x - i + 1 >= 3)
          mini1 = min(mini1, x - i + 1);
        else
          mini1 = min(mini1, (long long int)3);
      }
      if (prime[x / i] == x / i) {
        if (x - x / i + 1 >= 3)
          mini1 = min(mini1, x - x / i + 1);
        else
          mini1 = min(mini1, (long long int)3);
      }
    }
  }
  if (i * i == x)
    if (prime[i] == i) {
      if (x - i + 1 >= 3)
        mini1 = min(mini1, x - i + 1);
      else
        mini1 = min(mini1, (long long int)3);
    }
  long long int mini = INT_MAX;
  for (int j = mini1; j <= x; j++) {
    long long int x = j;
    long long int i = j;
    while (prime[i] != i) {
      if (x - prime[i] + 1 >= 3)
        mini = min(x - prime[i] + 1, mini);
      else {
        mini = 3;
      }
      i = i / prime[i];
    }
  }
  cout << mini << "\n";
}
