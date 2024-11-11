#include <bits/stdc++.h>
namespace {
const int L = 30;
std::vector<int> GetBits(int x) {
  std::vector<int> r(L);
  for (int i = L - 1; i >= 0; --i) {
    r[i] = (x % 2);
    x /= 2;
  }
  return r;
}
int GetValue(const std::vector<int>& r) {
  int value = 0;
  for (int bit : r) {
    value = (2 * value) + bit;
  }
  return value;
}
std::vector<int> AskAnd(int x, int y) {
  printf("and %d %d\n", x, y);
  fflush(stdout);
  int answer;
  scanf("%d", &answer);
  return GetBits(answer);
}
void ApplyAndResult(std::vector<std::vector<int>>* a_ptr, int x, int y,
                    const std::vector<int>& and_r) {
  std::vector<std::vector<int>>& a = (*a_ptr);
  for (int k = 0; k < L; ++k) {
    if (and_r[k] == 1) {
      a[x][k] = a[y][k] = 1;
    } else {
      if (a[x][k] == 1) {
        a[y][k] = 0;
      } else if (a[y][k] == 1) {
        a[x][k] = 0;
      }
    }
  }
}
std::vector<int> AskOr(int x, int y) {
  printf("or %d %d\n", x, y);
  fflush(stdout);
  int answer;
  scanf("%d", &answer);
  return GetBits(answer);
}
void ApplyOrResult(std::vector<std::vector<int>>* a_ptr, int x, int y,
                   const std::vector<int>& or_r) {
  std::vector<std::vector<int>>& a = (*a_ptr);
  for (int k = 0; k < L; ++k) {
    if (or_r[k] == 0) {
      a[x][k] = a[y][k] = 0;
    } else {
      if (a[x][k] == 0) {
        a[y][k] = 1;
      } else if (a[y][k] == 0) {
        a[x][k] = 1;
      }
    }
  }
}
}  // namespace
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(L, -1));
  std::vector<int> and_1_2 = AskAnd(1, 2);
  std::vector<int> or_1_2 = AskOr(1, 2);
  std::vector<int> and_1_3 = AskAnd(1, 3);
  std::vector<int> or_1_3 = AskOr(1, 3);
  std::vector<int> and_2_3 = AskAnd(2, 3);
  std::vector<int> or_2_3 = AskOr(2, 3);
  ApplyAndResult(&a, 1, 2, and_1_2);
  ApplyOrResult(&a, 1, 2, or_1_2);
  ApplyAndResult(&a, 2, 3, and_2_3);
  ApplyOrResult(&a, 2, 3, or_2_3);
  ApplyAndResult(&a, 1, 3, and_1_3);
  ApplyOrResult(&a, 1, 3, or_1_3);
  ApplyAndResult(&a, 1, 2, and_1_2);
  ApplyOrResult(&a, 1, 2, or_1_2);
  for (int i = 4; i <= n; ++i) {
    std::vector<int> and_r = AskAnd(1, i);
    std::vector<int> or_r = AskOr(1, i);
    ApplyAndResult(&a, 1, i, and_r);
    ApplyOrResult(&a, 1, i, or_r);
  }
  std::vector<int> array;
  for (int i = 1; i <= n; ++i) {
    array.push_back(GetValue(a[i]));
  }
  std::sort(array.begin(), array.end());
  printf("finish %d\n", array[k - 1]);
  return 0;
}
