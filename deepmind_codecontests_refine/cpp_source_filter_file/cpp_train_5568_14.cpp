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
const int maxN = 1007;
int n, W[maxN], H[maxN];
void cleanup() {}
bool Read() {
  cleanup();
  if (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", W + i, H + i);
    }
    return true;
  }
  return false;
}
void Run() {
  int answer = 1000000000;
  for (int h = 1; h <= 1000; ++h) {
    int w = 0;
    bool ok = true;
    int can = n / 2;
    vector<int> gain;
    for (int i = 0; i < n; ++i) {
      if (W[i] > h && H[i] > h) {
        ok = false;
      } else if (W[i] <= h && H[i] <= h) {
        w += W[i];
        gain.push_back(W[i] - H[i]);
      } else if (W[i] > h) {
        w += W[i];
      } else {
        can--;
        w += H[i];
      }
    }
    if (ok && can >= 0) {
      sort(gain.begin(), gain.end());
      while (can >= 0 && !gain.empty() && gain.back() > 0) {
        w -= gain.back();
        --can;
        gain.pop_back();
      }
      check_min(answer, w * h);
    }
  }
  printf("%d\n", answer);
}
}  // namespace Solution
namespace StressTest {
long long GetTime() {
  long long res;
  asm volatile("rdtsc" : "=A"(res));
  return res;
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
