#include <bits/stdc++.h>
int main() {
  std::string s1, s2;
  getline(std::cin, s1);
  getline(std::cin, s2);
  int n;
  scanf("%d", &n);
  char c1, c2;
  int n1, n2;
  int check1[100]{}, check2[100]{};
  for (int i = 0; i < n; ++i) {
    scanf("%d%*[ ]%c%d%*[ ]%c", &n1, &c1, &n2, &c2);
    if (c1 == 'h') {
      if (c2 == 'y')
        check1[n2] += 1;
      else
        check1[n2] += 2;
      if (check1[n2] >= 2) {
        std::cout << s1 << " " << n2 << " " << n1 << "\n";
        check1[n2] = INT_MIN;
      }
    } else {
      if (c2 == 'y')
        check2[n2] += 1;
      else
        check2[n2] += 2;
      if (check2[n2] >= 2) {
        std::cout << s2 << " " << n2 << " " << n1 << "\n";
        check2[n2] = INT_MIN;
      }
    }
  }
}
