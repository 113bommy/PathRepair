#include <bits/stdc++.h>
const int32_t max = 101;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int32_t n, pos, l, r;
  std::cin >> n >> pos >> l >> r;
  int32_t answ = 0;
  if (pos >= l && pos <= r) {
    if (pos - l <= r - pos) {
      if (l != 1) {
        answ = pos - l + 1;
        pos = l;
      }
      if (r != n) {
        answ += r - pos + 1;
      }
    } else {
      if (r != n) {
        answ += r - pos + 1;
        pos = r;
      }
      if (l != 1) {
        answ = pos - l + 1;
      }
    }
  } else {
    if (pos < l) {
      answ = l - pos + 1;
      pos = l;
      if (r != n) {
        answ += (r - l) + 1;
      }
    } else {
      answ = pos - r + 1;
      pos = r;
      if (l != 1) {
        answ += (r - l) + 1;
      }
    }
  }
  std::cout << answ;
  return 0;
}
