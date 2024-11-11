#include <bits/stdc++.h>
using namespace std;
string i2s(int value) {
  ostringstream out;
  out << value;
  return out.str();
}
int main(void) {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int i = 0, best = 0;
  string sans = "";
  for (; i < n; ++i) {
    if (a[i] == 1) {
      int c = 1;
      int p = 1;
      string cur = i2s(2000 + i + 1);
      for (int j = i + 1; j < n; ++j) {
        if (a[j] - p == 1) {
          ++c;
          p = a[j];
          cur += " " + i2s(2000 + j + 1);
        }
      }
      if (c > best) {
        sans = cur;
        best = c;
      }
    }
  }
  printf("%d\n", best);
  if (best) printf("%s\n", sans.c_str());
}
