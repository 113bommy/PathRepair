#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 10;
int a[maxn], cnt[maxn + 10000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  int sum = 0;
  for (int i = 0; i < maxn + 10000; i++) {
    if (cnt[i] > 1) {
      sum += cnt[i] - 1;
      cnt[i + 1] += cnt[i] - 1;
    }
  }
  cout << sum;
}
