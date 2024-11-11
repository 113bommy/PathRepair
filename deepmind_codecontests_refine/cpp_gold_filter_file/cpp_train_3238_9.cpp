#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
vector<pair<int, int> > pos, neg, zero;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    if (k < 0)
      neg.push_back({k, i + 1});
    else if (k > 0)
      pos.push_back({k, i + 1});
    else
      zero.push_back({k, i + 1});
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  if (neg.size() % 2 == 1 && zero.empty()) {
    if (!pos.empty() || neg.size() > 1)
      cout << 2 << " " << neg[neg.size() - 1].second << "\n";
    neg.pop_back();
  }
  if (!zero.empty()) {
    for (int i = 0; i < zero.size() - 1; ++i) {
      cout << 1 << " " << zero[i + 1].second << " " << zero[0].second << "\n";
    }
    if (neg.size() % 2 == 1) {
      cout << 1 << " " << neg[neg.size() - 1].second << " " << zero[0].second
           << "\n";
      neg.pop_back();
    }
    if (!pos.empty() || !neg.empty())
      cout << 2 << " " << zero[0].second << "\n";
    zero.clear();
  }
  int o;
  if (!pos.empty()) {
    o = pos[pos.size() - 1].second;
    pos.pop_back();
  } else if (!neg.empty()) {
    o = neg[neg.size() - 1].second;
    neg.pop_back();
  }
  for (int i = 0; i < pos.size(); ++i) {
    cout << 1 << " " << pos[i].second << " " << o << "\n";
  }
  for (int i = 0; i < neg.size(); ++i) {
    cout << 1 << " " << neg[i].second << " " << o << "\n";
  }
  return 0;
}
