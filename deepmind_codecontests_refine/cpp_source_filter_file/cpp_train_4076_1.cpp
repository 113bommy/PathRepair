#include <bits/stdc++.h>
using namespace std;
void out(const vector<int>& v) {
  cout << "next";
  for (auto a : v) {
    cout << ' ' << a;
  }
  cout << '\n';
  cout.flush();
}
int n;
array<int, 10> g;
void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (auto c : s) {
      g[c - '0'] = i;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    out({0, 1});
    read();
    out({0});
    read();
    if (g[0] == g[1]) break;
  }
  while (true) {
    out({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    read();
    if (g[0] == g[1]) break;
  }
  cout << "done\n";
  cout.flush();
  return 0;
}
