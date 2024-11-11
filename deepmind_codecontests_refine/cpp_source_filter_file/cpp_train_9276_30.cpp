#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int n, r, fr[100][101];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &r);
    for (int x, j = 0; j < r; j++) {
      scanf("%d", &x);
      fr[i][x]++;
    }
  }
  for (int i = 1; i <= 100; i++) {
    int c = 0;
    for (int j = 0; j <= 100; j++) {
      c += fr[j][i];
    }
    if (c == n) {
      ans.push_back(i);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    printf("%d", ans[i]);
    if (i != ans.size() - 1) putchar(' ');
  }
}
