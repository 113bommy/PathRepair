#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}
void solve() {
  int n, v;
  cin >> n >> v;
  vector<pair<int, int> > cb, kb;
  for (int i = 0; i < n; i++) {
    int type, cap;
    cin >> type >> cap;
    if (type == 1) {
      kb.push_back(make_pair(cap, i + 1));
    } else {
      cb.push_back(make_pair(cap, i + 1));
    }
  }
  sort(cb.begin(), cb.end(), comp);
  sort(kb.begin(), kb.end(), comp);
  long long ans = 0;
  vector<int> chosenIdx;
  if (v % 2 == 1 && !kb.empty()) {
    ans += kb.back().first;
    chosenIdx.push_back(kb.back().second);
    kb.pop_back();
  }
  while (v >= 2) {
    int c1 = 0, c2 = 0;
    vector<pair<int, int> > temp1, temp2;
    for (int i = 0; i < 2; i++) {
      if (!kb.empty()) {
        c1 += kb.back().first;
        temp1.push_back(kb.back());
        kb.pop_back();
      }
    }
    if (!cb.empty()) {
      c2 += cb.back().first;
      temp2.push_back(cb.back());
      cb.pop_back();
    }
    if (c1 > c2) {
      ans += c1;
      while (!temp1.empty()) {
        chosenIdx.push_back(temp1.back().second);
        temp1.pop_back();
        v--;
      }
      if (!temp2.empty()) cb.push_back(temp2.back());
    } else {
      ans += c2;
      if (!temp2.empty()) {
        chosenIdx.push_back(temp2.back().second);
        v -= 2;
      }
      reverse(temp1.begin(), temp1.end());
      while (!temp1.empty()) {
        kb.push_back(temp1.back());
        temp1.pop_back();
      }
    }
    if (cb.empty() && kb.empty()) break;
  }
  cout << ans << '\n';
  for (int idx : chosenIdx) {
    cout << idx << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
