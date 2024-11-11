#include <bits/stdc++.h>
using namespace std;
template <class T>
void printVector(std::vector<std::vector<T>> const &matrix) {
  for (std::vector<T> row : matrix) {
    for (T val : row) {
      std::cout << val << " ";
    }
    std::cout << '\n';
  }
}
static void solve() {
  int n;
  cin >> n;
  char D = 'D';
  char star = '*';
  std::vector<std::vector<char>> matrix(n, std::vector<char>(n, star));
  int mid = n / 2;
  int from = mid;
  int to = mid;
  for (int i = 0; i < n; i++) {
    for (int j = from; j <= to; j++) {
      matrix[i][j] = D;
    }
    if (i >= mid) {
      from++;
      to--;
    } else {
      from--;
      to++;
    }
  }
  printVector(matrix);
}
int main() {
  solve();
  return 0;
}
