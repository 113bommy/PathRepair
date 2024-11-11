#include <bits/stdc++.h>
using namespace std;
int N, ops;
bool u[257];
int nums[257];
struct Teak {
  int a, b, k;
};
Teak teak[1000];
void print_solution() {
  cout << ops << endl;
  for (int _n(ops), i(0); i < _n; i++) {
    const int n = teak[i].a + teak[i].b * teak[i].k;
    cout << "lea e" << char('a' + nums[n]) << "x, [";
    if (teak[i].a) {
      cout << "e" << char('a' + nums[teak[i].a]) << "x + ";
    }
    cout << teak[i].k << "*e" << char('a' + nums[teak[i].b]) << "x]" << endl;
  }
  exit(0);
}
void solve(int step) {
  if (step == ops) {
    if (u[N]) print_solution();
    return;
  }
  for (int k = 2; k <= 8; k *= 2) {
    for (int _n(N + 1), i(0); i < _n; i++)
      if (i == 0 || u[i]) {
        for (int _n(N + 1), j(0); j < _n; j++)
          if (u[j] && i + k * j <= N && !u[i + k * j]) {
            u[i + j * k] = true;
            teak[step].a = i, teak[step].b = j, teak[step].k = k;
            nums[i + j * k] = step + 1;
            solve(step + 1);
            u[i + j * k] = false;
          }
      }
  }
}
int main() {
  memset((u), (0), sizeof(u)), memset((nums), (0), sizeof(nums));
  u[1] = true;
  cin >> N;
  for (ops = 0;; ++ops) solve(0);
  return 0;
}
