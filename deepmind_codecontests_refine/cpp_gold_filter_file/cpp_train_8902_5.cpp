#include <bits/stdc++.h>
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int a[n];
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int j = 0;
  for (int i = 0; i < n && j >= 0 && j < n; i++) {
    if (s[j] == '>')
      j += a[j];
    else if (s[j] == '<')
      j -= a[j];
  }
  if (j < 0 || j > n - 1)
    std::cout << "FINITE";
  else
    std::cout << "INFINITE";
  return 0;
}
