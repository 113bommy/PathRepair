#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a;
int b[200];
int bb[200];
int vis[200];
int pr[200];
int main() {
  int m, n;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int s, h;
    scanf("%d%d", &s, &h);
    a.push_back({s - 1, h});
    pr[s - 1] = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) cin >> b[i], bb[i] = b[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) b[j] = bb[j];
    vector<pair<int, int> > left, right;
    for (auto p : a) {
      if (p.first <= i)
        left.push_back(p);
      else
        right.push_back(p);
    }
    reverse(left.begin(), left.end());
    bool lok = true;
    bool rok = true;
    vector<int> res;
    for (int j = 0; j < left.size(); j++) {
      bool ok = true;
      long long h = left[j].second;
      vector<pair<int, int> > changes;
      for (int k = left[j].first; k <= i; k++) {
        if (b[k] != 0) {
          changes.push_back({b[k], k});
          h += b[k];
          b[k] = 0;
        }
        if (h < 0) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        for (auto p : changes) {
          b[p.second] = p.first;
        }
      } else {
        res.push_back(left[j].first);
      }
      if (j == left.size() - 1 && !ok) {
        lok = false;
      }
    }
    for (int j = 0; j < right.size(); j++) {
      bool ok = true;
      long long h = right[j].second;
      vector<pair<int, int> > changes;
      for (int k = right[j].first; k >= i; k--) {
        if (b[k] != 0) {
          changes.push_back({b[k], k});
          h += b[k];
          b[k] = 0;
        }
        if (h < 0) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        for (auto p : changes) {
          b[p.second] = p.first;
        }
      } else {
        res.push_back(right[j].first);
      }
      if (j == right.size() - 1 && !ok) {
        rok = false;
      }
    }
    if (lok && rok) {
      cout << i + 1 << endl;
      for (int i = 0; i < res.size(); i++) {
        cout << pr[res[i]] + 1 << " ";
        vis[res[i]] = 1;
      }
      for (int i = 0; i < a.size(); i++) {
        if (!vis[a[i].first]) {
          cout << pr[a[i].first] + 1 << " ";
        }
      }
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
