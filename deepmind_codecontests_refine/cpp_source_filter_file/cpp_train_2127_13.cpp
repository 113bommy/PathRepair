#include <bits/stdc++.h>
template <typename T>
std::ostream& operator<<(std::ostream& str, const std::vector<T>& v) {
  str << "[";
  for (auto n : v) str << n << ", ";
  str << "]";
  return str;
}
using namespace std;
vector<vector<int>> direct(3, vector<int>(3)), mat(3, vector<int>(3));
int memo[3][3][41];
long long cost(int n, int from, int to) {
  if (n == 0) return 0;
  if (memo[from][to][n] > 0) return memo[from][to][n];
  int temp = 3 - from - to;
  long long droute =
      cost(n - 1, from, temp) + direct.at(from).at(to) + cost(n - 1, temp, to);
  long long reroute1 = cost(n - 1, from, temp) + cost(n - 1, temp, to) +
                       direct.at(from).at(temp) + cost(n - 1, to, from) +
                       direct.at(temp).at(to) + cost(n - 1, from, temp) +
                       cost(n - 1, from, to);
  long long reroute2 = 2 * cost(n - 1, from, to) + direct.at(from).at(temp) +
                       cost(n - 1, to, from) + direct.at(temp).at(to);
  long long res = min(droute, min(reroute1, reroute2));
  memo[from][to][n] = res;
  return res;
}
int main() {
  for (auto& row : direct)
    for (auto& tij : row) cin >> tij;
  mat = direct;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k)
        mat.at(i).at(j) =
            min(mat.at(i).at(j), mat.at(i).at(k) + mat.at(k).at(j));
  int n;
  cin >> n;
  cout << cost(n, 0, 2) << endl;
}
