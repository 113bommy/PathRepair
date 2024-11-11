#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long x, k, c = 0;
  cin >> x >> k;
  long long y[x];
  for (int i = 0; i < x; i++) cin >> y[i];
  long long p;
  cin >> p;
  long long R[x];
  for (int i = 0; i < x; i++) {
    cin >> R[i];
  }
  priority_queue<long long> q;
  long long FF = k;
  long long ZZ = 0;
  bool ans = true;
  for (long long i = 0; i < x; i++) {
    if (FF < y[i]) {
      if (FF + (i + 1 - c) * p < y[i]) {
        ans = false;
        break;
      } else {
        q.push(-R[i]);
        while (!q.empty()) {
          FF += p;
          ZZ += (-q.top());
          q.pop();
          c++;
          if (FF >= y[i]) break;
        }
      }
    } else {
      q.push(-R[i]);
    }
  }
  cout << (ans ? ZZ : -1) << endl;
  return 0;
}
