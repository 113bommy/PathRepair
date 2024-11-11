#include <bits/stdc++.h>
using namespace std;
const long long INF = 4000000000000000000LL;
int main() {
  long long k1, k2, k3, t1, t2, t3;
  cin >> k1 >> k2 >> k3;
  cin >> t1 >> t2 >> t3;
  int n;
  cin >> n;
  vector<long long> embassy(n);
  for (int i = 0; i < n; ++i) cin >> embassy[i];
  int proc = 0;
  long long time = 0;
  queue<int> q1, q2, q3;
  queue<int> w1, w2, w3;
  vector<int> waiting(n);
  long long res = 0;
  while (true) {
    long long step = INF;
    if (proc < n) step = embassy[proc] - time;
    if (not w1.empty()) step = min(step, waiting[w1.front()] + t1 - time);
    if (not w2.empty()) step = min(step, waiting[w2.front()] + t2 - time);
    if (not w3.empty()) step = min(step, waiting[w3.front()] + t3 - time);
    if (step == INF) break;
    time += step;
    while (not w3.empty() and waiting[w3.front()] + t3 <= time) {
      res = max(res, time - embassy[w3.front()]);
      w3.pop();
    }
    while (not w2.empty() and waiting[w2.front()] + t2 <= time) {
      waiting[w2.front()] = time;
      q3.push(w2.front());
      w2.pop();
    }
    while (not w1.empty() and waiting[w1.front()] + t1 <= time) {
      waiting[w1.front()] = time;
      q2.push(w1.front());
      w1.pop();
    }
    while (proc < n and embassy[proc] <= time) {
      waiting[proc] = time;
      q1.push(proc++);
    }
    while (not q3.empty() and w3.size() < k3) {
      waiting[q3.front()] = time;
      w3.push(q3.front());
      q3.pop();
    }
    while (not q2.empty() and w2.size() < k2) {
      waiting[q2.front()] = time;
      w2.push(q2.front());
      q2.pop();
    }
    while (not q1.empty() and w1.size() < k1) {
      waiting[q1.front()] = time;
      w1.push(q1.front());
      q1.pop();
    }
  }
  cout << res << endl;
}
