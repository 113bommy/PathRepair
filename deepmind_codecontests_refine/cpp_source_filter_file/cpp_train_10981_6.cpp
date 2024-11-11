#include <bits/stdc++.h>
using namespace std;
int a[100000];
int n, l, r, x;
int sum = 0;
void dfs(int i, int num, int ge, int minn, int maxx, int flag) {
  if (flag == 0 && ge >= 2 && num >= l && num <= r && maxx != 0 &&
      minn != 100000 && maxx - minn >= x) {
    sum++;
    flag = 1;
  }
  if (i > n - 1) return;
  dfs(i + 1, num, ge, minn, maxx, flag);
  if (a[i] > maxx) {
    maxx = a[i];
  }
  if (a[i] < minn) {
    minn = a[i];
  }
  dfs(i + 1, num + a[i], ge + 1, minn, maxx, 0);
}
int main() {
  cin >> n >> l >> r >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dfs(0, 0, 0, 100000, 0, 0);
  cout << sum << endl;
}
