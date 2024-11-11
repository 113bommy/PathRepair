#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > arr(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr[i] = make_pair(a, i);
  }
  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());
  int q;
  cin >> q;
  vector<pair<pair<int, int>, int> > qu;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    qu.push_back(make_pair(make_pair(a, b), i));
  }
  vector<int> ans(q);
  sort(qu.begin(), qu.end());
  set<pair<int, int> > cur;
  int qui = 0;
  for (int i = 0; i < n; i++) {
    cur.insert(make_pair(arr[i].second, arr[i].first));
    while (qui < q && qu[qui].first.first < i + 1) qui++;
    if (qui == q || qu[qui].first.first > i + 1) continue;
    while (qui < q && qu[qui].first.first == i + 1) {
      int ind = qu[qui].first.first - qu[qui].first.second;
      auto it = cur.begin();
      advance(it, ind);
      ans[qui] = it->second;
      qui++;
    }
  }
  vector<int> realans(q);
  for (int i = 0; i < q; i++) {
    realans[qu[i].second] = ans[i];
  }
  for (int i = 0; i < q; i++) cout << realans[i] << ' ';
  cout << endl;
}
