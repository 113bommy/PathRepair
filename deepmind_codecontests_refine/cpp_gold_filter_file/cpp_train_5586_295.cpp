#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int magic = 3;
void solve();
void dump(const vector<int>& a) {
  for (int i = 0; i < a.size(); i++) {
    cerr << a[i] << ' ';
  }
  cerr << endl;
}
template <typename T, int N>
void dump(const array<T, N>& a) {
  for (int i = 0; i < a.size(); i++) {
    cerr << a[i] << ' ';
  }
  cerr << endl;
}
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
const int SZ = 210;
void solve() { cout << "black" << endl; }
