#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, cur = 1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (a[i] >= cur) {
      cur++;
    }
  }
  cout << cur;
}
