#include <bits/stdc++.h>
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(static_cast<std::ostream*>(nullptr));
  int N, W;
  std::vector<int> n;
  int count, sum, i, j;
  int one_position, low_position;
  std::cin >> N >> W;
  sum = 0;
  one_position = 0;
  low_position = 0;
  n.resize(N + 1);
  for (i = 1; i <= N; ++i) {
    std::cin >> n[i];
    sum += n[i];
    if (n[i] == 1) {
      one_position = i;
    }
    if (n[i] <= W) {
      low_position = i;
    }
  }
  if (0 < W && W <= sum) {
    if (N == 1) {
      if (n[1] == W) {
        std::cout << "Yes" << std::endl;
        for (i = 0; i < n[1]; ++i) {
          std::cout << "1 1 ";
        }
        std::cout << std::endl;
      } else {
        std::cout << "No" << std::endl;
      }
    } else if (W == 1) {
      if (one_position != 0) {
        std::cout << "Yes" << std::endl;
        std::cout << one_position << " ";
        for (i = 1; i <= N; ++i) {
          if (i != one_position) {
            for (j = 0; j < n[i]; ++j) {
              std::cout << i << " " << i << " ";
            }
          }
        }
        std::cout << one_position << std::endl;
      } else {
        std::cout << "No" << std::endl;
      }
    } else {
      if (low_position != 0) {
        std::cout << "Yes" << std::endl;
        for (i = 1; i < n[low_position]; ++i) {
          std::cout << low_position << " " << low_position << " ";
        }
        if (n[low_position] == W) {
          std::cout << low_position << " ";
          for (i = 1; i <= N; ++i) {
            if (i != low_position) {
              for (j = 0; j < n[i]; ++j) {
                std::cout << i << " " << i << " ";
              }
            }
          }
        } else {
          i = 1;
          j = 0;
          count = n[low_position];
          while (count < W) {
            if (j == n[i]) {
              j = 0;
              ++i;
            }
            if (i == low_position) {
              ++i;
            }
            ++j;
            ++count;
            std::cout << i << " " << i << " ";
          }
          std::cout << low_position << " ";
          while (true) {
            if (j == n[i]) {
              j = 0;
              ++i;
            }
            if (i == low_position) {
              ++i;
            }
            if (i > N) {
              break;
            }
            ++j;
            std::cout << i << " " << i << " ";
          }
        }
        std::cout << low_position << std::endl;
      } else {
        std::cout << "Yes" << std::endl;
        for (i = 2; i < W; ++i) {
          std::cout << "1 1 ";
        }
        std::cout << "1 ";
        for (j = 1; j < n[2]; ++j) {
          std::cout << "2 2 ";
        }
        std::cout << "1 2 ";
        for (; i <= n[1]; ++i) {
          std::cout << "1 1 ";
        }
        for (i = 3; i <= N; ++i) {
          for (j = 0; j < n[i]; ++j) {
            std::cout << i << " " << i << " ";
          }
        }
        std::cout << "2" << std::endl;
      }
    }
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
