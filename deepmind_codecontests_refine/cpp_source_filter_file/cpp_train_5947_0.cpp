#include <bits/stdc++.h>
using namespace std;
void debug(int n, ...) {
  va_list v1;
  va_start(v1, n);
  for (int i = 0; i < n; i++) {
    int val = va_arg(v1, int);
    printf("%d ", val);
  }
  va_end(v1);
  printf("\n");
}
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] != s[i + 1]) {
      cout << "YES\n" << s[i] << " " << s[i + 1];
      return 0;
    }
  }
  printf("NO");
}
