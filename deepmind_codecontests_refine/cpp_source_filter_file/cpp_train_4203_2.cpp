#include <bits/stdc++.h>
using std::cin;
using std::cout;
const int POWERS_COUNT = 500 + 1;
int64_t powers[2][POWERS_COUNT];
std::map<int, std::vector<int64_t> > patterns;
int main() {
  std::ios_base::sync_with_stdio(false);
  cout.precision(11);
  powers[0][0] = powers[1][0] = 1LL;
  for (int i = 1; i < POWERS_COUNT; ++i) {
    powers[0][i] = powers[0][i - 1] * 5LL;
    powers[1][i] = powers[1][i - 1] * 7LL;
  }
  for (int a = 0; a < 2; ++a) {
    for (int b = 0; b < 2; ++b) {
      for (int c = 0; c < 2; ++c) {
        for (int d = 0; d < 2; ++d) {
          int A[2][2] = {{a, b}, {c, d}};
          static int M[500][500][2];
          for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
              M[i][j][0] = A[i][j];
            }
          }
          for (int len = 4, turn = 0; len <= 500; len *= 2, turn = 1 - turn) {
            for (int i = 0; i < len; ++i) {
              for (int j = 0; j < len; ++j) {
                if (M[i / 2][j / 2][turn] == 1) {
                  M[i][j][1 - turn] = 1;
                } else {
                  M[i][j][1 - turn] = A[i % 2][j % 2];
                }
              }
            }
            int64_t hash = 0;
            for (int i = 0; i < len; ++i) {
              for (int j = 0; j < len; ++j) {
                hash += M[i][j][1 - turn] * powers[0][i] * powers[1][j];
              }
            }
            patterns[len].push_back(hash);
          }
        }
      }
    }
  }
  int N, M;
  static int A[500][500];
  char buf[1000];
  cin >> N >> M;
  cin.getline(buf, 1000);
  for (int i = 0; i < N; ++i) {
    cin.getline(buf, 1000);
    for (int j = 0; j < M; ++j) {
      A[N - i - 1][j] = buf[j] == '.' ? 0 : 1;
    }
  }
  static int64_t H[500][500];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int64_t h1 = i > 0 ? H[i - 1][j] : 0;
      int64_t h2 = j > 0 ? H[i][j - 1] : 0;
      int64_t h3 = (i > 0 && j > 0) ? H[i - 1][j - 1] : 0;
      H[i][j] = A[i][j] * powers[0][i] * powers[1][j] + h1 + h2 - h3;
    }
  }
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int lim = std::min(N - i, M - j);
      for (int len = 4; len <= lim; len *= 2) {
        int64_t h1 = i > 0 ? H[i - 1][j + len - 1] : 0;
        int64_t h2 = j > 0 ? H[i + len - 1][j - 1] : 0;
        int64_t h3 = (i > 0 && j > 0) ? H[i - 1][j - 1] : 0;
        int64_t hh = H[i + len - 1][j + len - 1] - h1 - h2 + h3;
        const std::vector<int64_t>& p = patterns[len];
        for (size_t index = 0; index < p.size(); ++index) {
          if (powers[0][i] * powers[1][j] * p[index] == hh) {
            ++count;
            break;
          }
        }
      }
    }
  }
  cout << count << '\n';
  return 0;
}
