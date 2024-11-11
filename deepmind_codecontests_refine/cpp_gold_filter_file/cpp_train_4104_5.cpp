#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1000 + 5;
int a[N];
int cnt[N][N];
int ans = 0;
int per = 0;
int maxi = 0;
int n;
void pre() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) {
        per++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      cnt[i][j] = cnt[i][j + 1];
      if (a[i] < a[j]) {
        cnt[i][j]++;
      }
    }
    for (int j = i + 1; j < n; j++) {
      cnt[i][j] = cnt[i][j - 1];
      if (a[i] > a[j]) {
        cnt[i][j]++;
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  pre();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int tmp = 2 * (cnt[i][j] + cnt[j][i] - (j - i)) + 1;
      if (a[j] < a[i]) {
        tmp--;
        tmp--;
      }
      if (tmp > maxi) {
        maxi = tmp;
        ans = 0;
      }
      if (tmp == maxi) {
        ans++;
      }
    }
  }
  cout << per - maxi << "  " << ans;
}
