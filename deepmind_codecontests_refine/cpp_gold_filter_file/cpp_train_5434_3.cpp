#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
void DEBUG(string label, T value) {
  cerr << "[" << label << " = " << value << "]\n";
}
int beauty(string &a) {
  int ret = 0;
  vector<int> ar(a.size(), 0);
  int low = 1 << 30;
  for (int i = 0; i < a.size(); ++i) {
    if (i > 0) {
      ar[i] = ar[i - 1];
    }
    if (a[i] == '(') {
      ar[i]++;
    } else {
      ar[i]--;
    }
    low = min(low, ar[i]);
  }
  for (auto i : ar) {
    ret += (low == i);
  }
  return ret;
}
void solve() {
  int n;
  string a;
  cin >> n;
  cin >> a;
  int c1 = 0;
  for (auto c : a) {
    if (c == '(') ++c1;
  }
  if (c1 != n - c1) {
    cout << 0 << endl << 1 << " " << 1 << endl;
    return;
  }
  int best = beauty(a);
  int p1 = 0;
  int p2 = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      swap(a[i], a[j]);
      int cur = beauty(a);
      swap(a[i], a[j]);
      if (cur > best) {
        best = cur;
        p1 = i;
        p2 = j;
      }
    }
  }
  cout << best << endl;
  if (best == 0) {
    cout << 1 << " " << 1 << endl;
  } else {
    cout << p1 + 1 << " " << p2 + 1 << endl;
  }
}
int main(int argv, char **argc) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
