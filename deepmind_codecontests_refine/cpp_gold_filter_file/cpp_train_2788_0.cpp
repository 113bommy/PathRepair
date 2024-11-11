#include <bits/stdc++.h>
using namespace std;

void solve(std::istream &in, std::ostream &out);

int main() {
#ifdef LOCAL
  freopen("../IO/e.in", "r", stdin);
//  freopen("../IO/e.out", "w", stdout);
#else
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  solve(std::cin, std::cout);
  return 0;
}

int mp[1 << 11][1 << 11];
void solve(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  bool swapped = false;
  mp[1][1] = 1;
  for (int len = 1; len < max(n, m); ++len) {
    int L = 1 << len;
    mp[L][L] = 1;
    for (int i = 1; i < L; ++i) {
      for (int j = 1; j < L; ++j) {
        mp[i + L][j + L] = mp[i + L][j] = mp[i][j + L] = mp[i][j];
      }
    }
  }
  for (int i = 1; i < 1 << n; ++i) {
    for (int j = 1; j < 1 << m; ++j) {
      out << char('0' + mp[i][j]);
    }
    out << '\n';
  }
}

