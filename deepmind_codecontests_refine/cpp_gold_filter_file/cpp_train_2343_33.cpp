#include <bits/stdc++.h>
using namespace std;
int ans[1010202];
int a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a;
  for (int b = 0; b < a; b++) {
    int k;
    cin >> k;
    ans[k]++;
  }
  int counte = 0;
  for (int b = 0; b < 1010100; b++) {
    if (ans[b] % 2) counte++;
    ans[b + 1] += ans[b] / 2;
  }
  cout << counte << "\n";
}
