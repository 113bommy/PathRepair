#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxN = 100 * 1024;
int N, K;
int a[maxN];
int lis[maxN];
int main() {
  cin >> N;
  for (int i = (1); i < (N + 1); i++) cin >> a[i];
  for (int i = (1); i < (N + 2); i++) lis[i] = oo;
  for (int i = (1); i < (N + 1); i++) {
    int len = upper_bound(lis + 1, lis + N + 1, a[i]) - lis;
    lis[len] = min(lis[len], a[i]);
  }
  int best = lower_bound(lis + 1, lis + N + 2, oo) - lis - 1;
  cout << best << endl;
}
