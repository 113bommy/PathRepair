#include <bits/stdc++.h>
using namespace std;
const int M = 100 * 1000 + 10;
long long p[M];
int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    p[d]++;
  }
  long long q = 0;
  if (x != 0) {
    for (int i = 0; i < M; i++) {
      if (p[i] > 0) {
        long long t = i ^ x;
        if (t < M) {
          q += p[t] * p[i];
        }
      }
    }
    cout << q / 2;
  } else {
    for (int i = 0; i < M; i++) {
      if (p[i] > 0) {
        q += p[i] * (p[i] - 1) / 2;
      }
    }
    cout << q;
  }
}
