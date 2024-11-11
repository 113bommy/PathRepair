#include <bits/stdc++.h>
using namespace std;
long long int no_of_ones(long long int n) { return __builtin_popcount(n); }
long long int setmask(long long int mask, long long int i) {
  return mask | (1 << i);
}
long long int unsetmask(long long int mask, long long int i) {
  return (mask & !(1 << i));
}
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, 0};
long long int pwr(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b % 2 == 0)
    return pwr((a * a) % 998244353, b / 2);
  else
    return (a * pwr((a * a) % 998244353, b / 2)) % 998244353;
}
long long int forest[1000000][2];
long long int par(long long int node) {
  while (forest[node][0] != node) {
    node = forest[node][0];
  }
  return node;
}
long long int join(long long int n1, long long int n2) {
  if (forest[n1][1] < forest[n2][1]) {
    swap(n1, n2);
  }
  forest[n2][0] = n1;
  forest[n1][1] += forest[n2][1];
}
long long int seive[10000001];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  for (long long int j = 0; j < 10000001; j += 1) {
    seive[j] = 0;
  }
  for (long long int i = 2; i <= 4000; i++) {
    if (seive[i] == 0) {
      for (long long int j = i; j < 10000001; j += i) {
        if (seive[j] == 0) seive[j] = i;
      }
    }
  }
  for (long long int j = 0; j < 10000001; j += 1) {
    if (seive[j] == 0) seive[j] = j;
  }
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n], ans1[n], ans2[n];
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
      if (seive[arr[i]] == 2) {
        long long int a = arr[i];
        long long int b = 1;
        while (a % 2 == 0) {
          a /= 2;
          b *= 2;
        }
        if (a == 1) {
          ans1[i] = ans2[i] = -1;
        } else {
          ans1[i] = b;
          ans2[i] = a;
        }
      } else {
        long long int a = arr[i];
        long long int x = seive[a];
        while (a % x == 0) {
          a /= x;
        }
        if (a == 1) {
          ans1[i] = ans2[i] = -1;
        } else {
          ans1[i] = x;
          ans2[i] = seive[a];
        }
      }
    }
    for (long long int i = 0; i < n; i++) {
      cout << ans1[i] << " ";
    }
    cout << '\n';
    for (long long int i = 0; i < n; i++) {
      cout << ans2[i] << " ";
    }
    cout << '\n';
  }
}
