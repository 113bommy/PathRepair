#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[100010];
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  int64_t s1 = 0;
  for (size_t i = 1; i < n; i++) {
    if (a[i - 1] > a[i]) s1 += a[i - 1] - a[i];
  }
  cout << s1;
  return 0;
}
