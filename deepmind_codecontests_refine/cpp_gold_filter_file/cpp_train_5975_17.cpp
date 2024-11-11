#include <bits/stdc++.h>
const int nmax = 1e5 + 5;
std::pair<std::pair<int, int>, std::pair<int, int> > v[nmax];
int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> v[i].first.first;
    v[i].first.second = i;
  }
  std::sort(v, v + n);
  int k = n / 3;
  if (n % 3 != 0) k++;
  for (int i = 0; i < k; i++) {
    v[i].second.first = i;
    v[i].second.second = v[i].first.first - v[i].second.first;
  }
  for (int i = k; i < 2 * k; i++) {
    v[i].second.second = i;
    v[i].second.first = v[i].first.first - v[i].second.second;
  }
  for (int i = 2 * k; i < n; i++) {
    v[i].second.second = n - i - 1;
    v[i].second.first = v[i].first.first - v[i].second.second;
  }
  for (int i = 0; i < n; i++) std::swap(v[i].first.first, v[i].first.second);
  std::sort(v, v + n);
  std::cout << "YES\n";
  for (int i = 0; i < n; i++) std::cout << v[i].second.first << " ";
  std::cout << "\n";
  for (int i = 0; i < n; i++) std::cout << v[i].second.second << " ";
}
