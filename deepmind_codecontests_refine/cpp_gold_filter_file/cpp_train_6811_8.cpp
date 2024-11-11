#include <bits/stdc++.h>
std::unordered_map<int, int> M;
int C[505 * 32][505];
void add(int x) {
  if (M.find(x) == M.end()) {
    M[x] = 1;
  } else {
    M[x]++;
  }
}
int main() {
  int N;
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    int x;
    std::cin >> x;
    for (int j = 2; j <= sqrt(x); j++) {
      while (x % j == 0) {
        x /= j;
        add(j);
      }
    }
    if (x != 1) {
      add(x);
    }
  }
  for (int i = 0; i <= 32 * N; i++) {
    C[i][0] = 1;
  }
  for (int i = 1; i <= N * 32; i++) {
    for (int j = 1; j <= N; j++) {
      C[i][j] = (0LL + C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
    }
  }
  int total = 1;
  for (std::pair<int, int> el : M) {
    total = (1LL * total * C[el.second + N - 1][N - 1]) % 1000000007;
  }
  std::cout << total << "\n";
}
