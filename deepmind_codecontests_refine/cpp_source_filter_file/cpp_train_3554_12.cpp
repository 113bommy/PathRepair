#include <bits/stdc++.h>
using namespace std;
int n, k, a[1010], ac, now, stt[1010], res;
vector<double> fq;
priority_queue<double, vector<double>, greater<double> > pq;
map<double, int> mp;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int i = 0;
  for (double t = 0; t <= 150000; t += 0.5) {
    while (!pq.empty() && pq.top() == t) {
      pq.pop();
      ac++;
    }
    while (i < n && pq.size() < k) {
      stt[i] = t;
      pq.push(t + a[i]);
      i++;
    }
    mp[t + 0.5] = round(ac * 100.0 / n);
  }
  for (int i = 0; i < n; i++) {
    int test = 1;
    for (double t = stt[i] + 0.5; test < a[i]; t += 0.5) {
      if (mp[t] == test) {
        res++;
        break;
      }
      if (int(t) == t) test++;
    }
  }
  cout << res;
}
