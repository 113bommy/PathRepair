#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  int zz = 0, oo = 0, zo = 0, oz = 0;
  std::string ss[2];
  std::cin >> ss[0] >> ss[1];
  int arr[n][2];
  for (int j = 0; j < 2; ++j) {
    for (int i = 0; i < n; ++i) {
      arr[i][j] = ss[j][i] - '0';
    }
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i][0] == 0 && arr[i][1] == 0) {
      ++zz;
      continue;
    }
    if (arr[i][0] == 0 && arr[i][1] == 1) {
      ++zo;
      continue;
    }
    if (arr[i][0] == 1 && arr[i][1] == 0) {
      ++oz;
      continue;
    }
    if (arr[i][0] == 1 && arr[i][1] == 1) {
      ++oo;
      continue;
    }
  }
  for (int i = 0; i <= oo; ++i) {
    for (int j = 0; j <= oz; ++j) {
      int m1 = n / 2 - i - j;
      int m2 = n / 2 - oo - oz + i + j;
      if (m1 < 0 || m2 < 0) {
        continue;
      }
      int o1 = i + j;
      int o2 = oo - i;
      int l_o2 = o2 + std::max(0, zo - m1);
      int r_o2 = o2 + std::min(m2, zo);
      if (o1 < l_o2 || o1 > r_o2) {
        continue;
      }
      int rzz, rzo, roz, roo;
      roo = i;
      roz = j;
      rzo = zo - o1 + o2;
      rzz = n / 2 - roo - roz - rzo;
      for (int k = 0; k < n; ++k) {
        if (arr[k][0] == 0 && arr[k][1] == 0 && rzz > 0) {
          --rzz;
          std::cout << k + 1 << " ";
          continue;
        }
        if (arr[k][0] == 0 && arr[k][1] == 1 && rzo > 0) {
          --rzo;
          std::cout << k + 1 << " ";
          continue;
        }
        if (arr[k][0] == 1 && arr[k][1] == 0 && roz > 0) {
          --roz;
          std::cout << k + 1 << " ";
          continue;
        }
        if (arr[k][0] == 1 && arr[k][1] == 1 && roo > 0) {
          --roo;
          std::cout << k + 1 << " ";
          continue;
        }
      }
      std::cout << std::endl;
      return 0;
    }
  }
  std::cout << -1 << std::endl;
  return 0;
}
