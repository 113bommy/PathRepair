#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int n, t[M], mx = 2e9, k;
priority_queue<pair<int, int> > neg, pos;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    if (t[i] >= 0) t[i] = -t[i] - 1;
    if (t[i] < mx) {
      mx = t[i];
      k = i;
    }
  }
  if (n % 2) {
    t[k] = -t[k] - 1;
  }
  for (int i = 0; i < n; i++) cout << t[i] << ' ';
  puts("");
}
