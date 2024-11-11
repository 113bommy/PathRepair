#include <bits/stdc++.h>
using namespace std;
long long int mini = (int)1e9;
int n;
int h[1001];
int w[1001];
int a[1001];
int b[1001];
long long int solve(int l) {
  int lim = n / 2;
  for (int i = 0; i < n; i++) {
    a[i] = h[i];
    b[i] = w[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > l) {
      if (b[i] > l) {
        return (int)1e9;
      }
      swap(a[i], b[i]);
      cnt++;
    }
  }
  if (cnt > lim) return (int)1e9;
  vector<int> tmp;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = sum + b[i];
    if (a[i] < b[i]) {
      if (b[i] <= l) tmp.push_back(a[i] - b[i]);
    }
  }
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < min((int)tmp.size(), lim - cnt); i++) {
    sum = sum + tmp[i];
  }
  return sum;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    scanf("%d", &h[i]);
  }
  for (int i = 1; i <= 1000; i++) {
    mini = min(i * solve(i), mini);
  }
  printf("%lld\n", mini);
}
