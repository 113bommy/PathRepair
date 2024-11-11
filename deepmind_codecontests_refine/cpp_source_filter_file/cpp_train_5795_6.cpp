#include <bits/stdc++.h>
int main(int argc, char** argv) {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);
  std::cout << std::fixed << std::setprecision(6);
  std::cerr << std::fixed << std::setprecision(6);
  int n, m[111111], o[111111];
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> m[i];
  o[0] = 0;
  for (int i = 1; i < n; i++) o[i] = std::max(m[i], o[i - 1]);
  for (int i = n - 2; i >= 0; i--)
    if (o[i] < o[i + 1] - 1) o[i] = o[i + 1] - 1;
  for (int i = 0; i < n; i++) o[i]++;
  int c = 0;
  for (int i = 0; i < n; i++) c += o[i] - m[i] - 1;
  std::cout << c << std::endl;
  return 0;
}
