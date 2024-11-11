#include <bits/stdc++.h>
int Compare(std::string a, std::string b) {
  if (a.size() != b.size()) {
    return 0;
  }
  int k = 0;
  for (int i = 0; i < a.size(); i++) {
    k += a[i] == b[i];
  }
  return k;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  std::string a;
  std::string variants[] = {"vaporeon", "jolteon", "flareon", "espeon",
                            "umbreon",  "leafeon", "glaceon", "sylveon"};
  std::cin >> a;
  int maximal = -1, var, k = 0;
  for (int i = 0; i < 8; i++) {
    k = Compare(a, variants[i]);
    if (k > maximal) {
      maximal = k;
      var = i;
    }
  }
  std::cout << variants[var];
}
