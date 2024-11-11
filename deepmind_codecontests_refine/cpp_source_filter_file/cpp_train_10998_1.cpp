#include <bits/stdc++.h>
using namespace std;
long long a[200000];
long long b[200000];
long long sum[200000];
long long ans[200000];
long long num[200000];
int main(int argc, char *argv[]) {
  int N, l, r, mid;
  while (cin >> N) {
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
      cin >> b[i];
      sum[i] = sum[i - 1] + b[i];
    }
    for (int i = 1; i <= N; i++) {
      l = i - 1;
      r = N;
      while (l != r) {
        mid = (l + r + 1) / 2;
        if (a[i] >= sum[mid] - sum[i - 1])
          l = mid;
        else
          r = mid - 1;
      }
      num[i]++;
      num[l + 1]--;
      ans[l + 1] = a[i] - (sum[l] - sum[i - 1]);
    }
    for (int i = 1; i <= N; i++) {
      num[i] += num[i - 1];
      cout << (num[i] * b[i] + ans[i]) << " ";
    }
  }
}
