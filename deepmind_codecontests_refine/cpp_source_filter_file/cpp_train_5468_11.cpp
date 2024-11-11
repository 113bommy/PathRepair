#include <bits/stdc++.h>
using namespace std;
int n, m, a[200000], ret[200000];
deque<pair<int, int> > q;
int main() {
  cin >> n >> m;
  for (int i = int(0); i < int(n); i++) cin >> a[i];
  int t, r;
  for (int i = int(0); i < int(m); i++) {
    cin >> t >> r;
    r--;
    while (!q.empty() && q.back().second <= r) q.pop_back();
    q.push_back(make_pair(t, r));
  }
  int left = 0, right = q.front().second;
  for (int i = int(right + 1); i < int(n); i++) ret[i] = a[i];
  sort(a, a + r + 1);
  q.push_back(make_pair(0, -1));
  while (q.size() > 1) {
    t = q.front().first;
    r = q.front().second;
    q.pop_front();
    for (int i = int(r); i > int(q.front().second); i--) {
      if (t == 2)
        ret[i] = a[left++];
      else
        ret[i] = a[right--];
    }
  }
  for (int i = int(0); i < int(n); i++) cout << ret[i] << " ";
  cout << endl;
  return 0;
}
