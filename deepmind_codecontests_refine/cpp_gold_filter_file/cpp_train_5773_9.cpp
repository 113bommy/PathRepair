#include <bits/stdc++.h>
static const int MOD = 1000000007;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using namespace std;
template <class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;
int main() {
  int n, m;
  cin >> n >> m;
  int y = 0, x = 0;
  if (n == 1 && m == 2) {
    printf("0\n1 1\n1 2\n1 1\n");
  } else if (n == 2 && m == 1) {
    printf("0\n1 1\n2 1\n1 1\n");
  } else if (n % 2 == 0 && m != 1) {
    puts("0");
    for (int i = 0; i < n; ++i) {
      printf("%d %d\n", i + 1, 1);
    }
    for (int i = n - 1; i >= 0; --i) {
      if ((n - i) & 1) {
        for (int j = 1; j < m; ++j) {
          printf("%d %d\n", i + 1, j + 1);
        }
      } else {
        for (int j = m - 1; j >= 1; --j) {
          printf("%d %d\n", i + 1, j + 1);
        }
      }
    }
    printf("%d %d\n", 1, 1);
  } else if (m % 2 == 0 && n != 1) {
    puts("0");
    for (int i = 0; i < m; ++i) {
      printf("%d %d\n", 1, i + 1);
    }
    for (int i = m - 1; i >= 0; --i) {
      if ((m - i) & 1) {
        for (int j = 1; j < n; ++j) {
          printf("%d %d\n", j + 1, i + 1);
        }
      } else {
        for (int j = n - 1; j >= 1; --j) {
          printf("%d %d\n", j + 1, i + 1);
        }
      }
    }
    printf("%d %d\n", 1, 1);
  } else {
    for (int i = 0; i < n; ++i) {
      x = i + 1;
      y = 1;
    }
    for (int i = n - 1; i >= 0; --i) {
      if ((n - i) & 1) {
        for (int j = 1; j < m; ++j) {
          x = i + 1;
          y = j + 1;
        }
      } else {
        for (int j = m - 1; j >= 1; --j) {
          x = i + 1;
          y = j + 1;
        }
      }
    }
    puts("1");
    printf("%d %d %d %d\n", x, y, 1, 1);
    for (int i = 0; i < n; ++i) {
      printf("%d %d\n", i + 1, 1);
    }
    for (int i = n - 1; i >= 0; --i) {
      if ((n - i) & 1) {
        for (int j = 1; j < m; ++j) {
          printf("%d %d\n", i + 1, j + 1);
        }
      } else {
        for (int j = m - 1; j >= 1; --j) {
          printf("%d %d\n", i + 1, j + 1);
        }
      }
    }
    printf("%d %d\n", 1, 1);
  }
  return 0;
}
