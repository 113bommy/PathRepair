#include <bits/stdc++.h>
using namespace std;
void IO(string Bessie);
int32_t main() {
  IO("");
  int N;
  cin >> N;
  vector<int> v(N);
  int a = 0, b = 0, c{};
  cout << "? 1 2" << endl;
  int ab;
  cin >> ab;
  cout << "? 2 3" << endl;
  int bc;
  cin >> bc;
  cout << "? 1 3" << endl;
  int abc;
  cin >> abc;
  a = abc - bc;
  b = ab - a;
  c = abc - ab;
  v[0] = a, v[1] = b, v[2] = c;
  for (int i = 4; i <= N; ++i) {
    int x;
    cout << "? " << i - 1 << ' ' << i << endl;
    cin >> x;
    v[i - 1] = x - v[i - 2];
  }
  cout << "! ";
  for (auto i : v) {
    cout << i << ' ';
  }
  cerr << "\nTime Elapsed: [" << 1e3 * clock() / CLOCKS_PER_SEC << " ms]\n";
}
void IO(string Bessie = "") {
  cin.tie(nullptr)->sync_with_stdio(false);
  if ((int)(Bessie).size()) {
    freopen((Bessie + ".in").c_str(), "r", stdin);
    freopen((Bessie + ".out").c_str(), "w", stdout);
  }
}
