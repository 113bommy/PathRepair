#include <bits/stdc++.h>
using namespace std;
int k;
char a[1000005];
int ans[1000005];
int cnt;
int num;
bool judge(int n) {
  int total = 1;
  int he = 0;
  for (int i = 2; i <= num; i++) {
    if (ans[i] > n) return false;
    if (he + ans[i] <= n) {
      he += ans[i];
    } else {
      he = ans[i];
      total++;
    }
  }
  if (total <= k) {
    return true;
  } else {
    return false;
  }
}
int main() {
  cin >> k;
  cin.get();
  cin.getline(a, 10000005, '\n');
  cnt = 0;
  num = 1;
  for (int i = 0; a[i] != '\0'; i++) {
    if (a[i] != '-' && a[i] != ' ') {
      cnt++;
    } else {
      ans[num++] = cnt + 1;
      cnt = 0;
    }
  }
  ans[num] = cnt;
  int l = 0, r = 1000000;
  while (l < r) {
    int mid = (l + r) / 2;
    if (judge(mid) == true)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
}
