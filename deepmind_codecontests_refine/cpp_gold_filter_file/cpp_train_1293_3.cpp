#include <bits/stdc++.h>
std::vector<std::string> adj(1000, std::string(1000, 'N'));
std::vector<int> factorize(int n) {
  std::vector<int> a;
  for (; n >= 2; n /= 2) a.push_back(2);
  return a;
}
int prod(const std::vector<int>& a) {
  int n = 1;
  for (const auto& i : a) n *= i;
  return n;
}
int main(int argc, char** argv) {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 2 << std::endl;
    std::cout << "NY" << std::endl;
    std::cout << "YN" << std::endl;
    return 0;
  }
  int l = 0;
  for (int nn = n; nn >= 2; nn /= 2) l++;
  std::map<int, std::vector<int>> map;
  map[1 << l].push_back(2);
  map[1 << l].push_back(3);
  for (int i = 0; i < l - 1; i++) {
    adj[i * 2 + 2][i * 2 + 4] = 'Y';
    adj[i * 2 + 2][i * 2 + 5] = 'Y';
    adj[i * 2 + 3][i * 2 + 4] = 'Y';
    adj[i * 2 + 3][i * 2 + 5] = 'Y';
  }
  adj[l * 2][1] = 'Y';
  adj[l * 2 + 1][1] = 'Y';
  int index = 2 + l * 2;
  for (int i = 1; i < l; index += i, i++) {
    map[1 << (l - i)].push_back(index);
    for (int j = 0; j < i - 1; j++) adj[index + j][index + j + 1] = 'Y';
    adj[index + i - 1][i * 2 + 2] = 'Y';
    adj[index + i - 1][i * 2 + 3] = 'Y';
  }
  for (int i = 0; i < l - 1; i++) adj[index + i][index + i + 1] = 'Y';
  adj[index + l - 1][1] = 'Y';
  map[1] = {index};
  for (int b = 1; n; b *= 2, n /= 2)
    if (n % 2 == 1)
      for (const auto& i : map[b]) adj[0][i] = 'Y';
  for (int i = 0; i < 1000; i++)
    for (int j = i + 1; j < 1000; j++)
      if (adj[i][j] == 'Y' || adj[j][i] == 'Y') adj[i][j] = adj[j][i] = 'Y';
  int size = 0;
  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++)
      if (adj[i][j] == 'Y') size = std::max({i + 1, j + 1, size});
  std::cout << size << std::endl;
  for (int i = 0; i < size; i++)
    std::cout << adj[i].substr(0, size) << std::endl;
  return 0;
}
