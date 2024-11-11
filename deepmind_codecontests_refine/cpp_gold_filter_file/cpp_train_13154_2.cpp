#include <bits/stdc++.h>
int main() {
  int n;
  char a[101];
  std::cin >> a;
  n = strlen(a);
  int count = 0;
  int c;
  for (int i = 97; i < 123; ++i) {
    c = 0;
    for (int j = 0; j < n; ++j)
      if (a[j] == char(i)) c++;
    if (c) count++;
  }
  if (count % 2)
    std::cout << "IGNORE HIM!";
  else
    std::cout << "CHAT WITH HER!";
  return 0;
}
