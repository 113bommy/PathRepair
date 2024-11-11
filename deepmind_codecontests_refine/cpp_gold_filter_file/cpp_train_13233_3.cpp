#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void check_max(T& actual, T check) {
  if (actual < check) {
    actual = check;
  }
}
template <class T>
inline void check_min(T& actual, T check) {
  if (actual > check) {
    actual = check;
  }
}
const double EPS = 1e-9;
const int IINF = 1000000000;
const double PI = acos(-1.0);
const long long LINF = 6000000000000000000LL;
namespace Solution {
const int MAXN = 200007;
int n, a[MAXN];
long long mmax[MAXN], f[MAXN], r[MAXN];
void cleanup() {
  memset(mmax, 0, sizeof(mmax));
  memset(f, 0, sizeof(f));
  memset(r, 0, sizeof(r));
}
bool Read() {
  cleanup();
  if (scanf("%d", &n) != 1) return false;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  return true;
}
void Run() {
  if (n == 1) return;
  long long sum = 0;
  f[0] = a[0];
  sum += a[0];
  for (int i = 1; i < n; ++i) {
    sum += a[i];
    f[i] = max(f[i - 1], (long long)a[i]);
  }
  r[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    r[i] = max(r[i + 1], (long long)a[i]);
  }
  std::vector<int> answer;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      if (sum - r[i + 1] - a[i] == r[i + 1]) {
        answer.push_back(i);
      }
    } else if (i == n - 1) {
      if (sum - f[i - 1] - a[i] == f[i - 1]) {
        answer.push_back(i);
      }
    } else {
      int mmax = max(f[i - 1], r[i + 1]);
      if (sum - a[i] - mmax == mmax) {
        answer.push_back(i);
      }
    }
  }
  printf("%d\n", answer.size());
  if (!answer.empty()) {
    for (int x : answer) {
      printf("%d ", x + 1);
    }
  }
  printf("\n");
}
}  // namespace Solution
namespace StressTest {
long long GetTime() {
  srand(time(NULL));
  return rand() << 16LL;
}
void GenerateInput() {
  FILE* output = fopen("input.txt", "w");
  srand(GetTime());
  fclose(output);
}
void BruteForce() {
  FILE* input = fopen("input.txt", "r");
  FILE* output = fopen("brute.out", "w");
  fclose(input);
  fclose(output);
}
}  // namespace StressTest
int main() {
  while (Solution::Read()) {
    Solution::Run();
  }
  return 0;
}
