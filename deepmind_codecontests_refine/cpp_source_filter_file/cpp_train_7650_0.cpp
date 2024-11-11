#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  bool Prime[1001];
  memset(Prime, 1, sizeof(Prime));
  for (long long i = 2; i <= 1000; ++i) {
    if (Prime[i]) {
      for (int j = i * 2; j <= 1000; j += i) {
        Prime[j] = 0;
      }
    }
  }
  vector<int> V;
  for (long long i = 2; i <= 100; ++i) {
    if (Prime[i]) {
      int x = i;
      while (x <= N) {
        V.push_back(x);
        x *= i;
      }
    }
  }
  int n = V.size();
  cout << n << endl;
  for (long long i = 0; i <= n - 1; ++i) {
    cout << V[i] << " ";
  }
  cout << endl;
  return 0;
}
