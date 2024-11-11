#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int lowbit(int x) { return x & (-x); }
int n;
int v[maxn];
vector<int> ans1, ans2;
long long maxx = 0;
long long p[35];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  long long tep = 0;
  for (register long long i = 1; i <= n; i++) {
    for (register long long j = 30; j >= 0; j--) {
      long long k = 1 << j;
      if (v[i] & k) {
        p[j]++;
      }
    }
  }
  long long tepp;
  for (register long long i = 0; i <= 30; i++) {
    if (p[i] == 1) {
      tepp = i;
      break;
    }
  }
  for (register long long i = 1; i <= n; i++) {
    long long k = 1 << tepp;
    if (v[i] & k) {
      tep = i;
      break;
    }
  }
  swap(v[1], v[tep]);
  for (register long long i = 1; i <= n; i++) {
    i == n ? cout << v[i] << endl : cout << v[i] << " ";
  }
  return 0;
}
