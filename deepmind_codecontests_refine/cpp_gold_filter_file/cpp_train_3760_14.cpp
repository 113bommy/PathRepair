#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e5 + 7;
int n;
int ask(int x) {
  std::cout << x << " 1" << '\n';
  std::cout << flush;
  string a;
  std::cin >> a;
  return a[0] - 'a';
}
int main() {
  std::cin >> n;
  int fst = ask(0);
  int l = 0, r = 1e9;
  for (int i = 0; i < n - 1; i++) {
    int mid = (l + r) / 2;
    if (ask(mid) == fst)
      l = mid;
    else
      r = mid;
  }
  std::cout << l << " " << 0 << " " << l + 1 << " " << 2 << '\n';
  std::cout << flush;
}
