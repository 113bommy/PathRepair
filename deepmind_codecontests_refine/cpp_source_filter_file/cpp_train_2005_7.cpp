#include <bits/stdc++.h>
int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int32_t t, n;
  std::string a, b;
  std::vector<int32_t> moves;
  std::cin >> t;
  while (t-- > 0) {
    std::cin >> n >> a >> b;
    moves.clear();
    int32_t f = 0;
    int32_t l = a.size() - 1;
    int32_t bl = b.size() - 1;
    while (f <= l) {
      if (a[l] == b[bl]) {
        l--;
        bl--;
        continue;
      }
      if (f == l) {
        moves.push_back(1);
        l--;
        continue;
      }
      if (a[f] == b[bl]) {
        moves.push_back(1);
      }
      moves.push_back(l + 1);
      moves.push_back(l);
      f++;
      bl--;
    }
    std::cout << moves.size();
    for (int32_t i : moves) {
      std::cout << " " << i;
    }
    std::cout << std::endl;
  }
  return 0;
}
