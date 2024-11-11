#include <bits/stdc++.h>
using namespace std;
int num[10][10];
int work(int n) {
  int rec = 0;
  while (n) {
    rec += n % 10;
    n /= 10;
  }
  return rec;
}
string ans;
string temp;
void s(int n, int mod) {
  if (n == 0) return;
  if (mod == 0) {
    if (n > 8) {
      n -= 8;
      int t = n / 9, p = n % 9;
      if (p) temp = p + '0';
      while (t--) temp += '9';
      temp += '8';
    } else {
      temp = '0' + n;
    }
  } else {
    int t = n / 9, p = n % 9;
    if (p) temp = p + '0';
    while (t--) temp += '9';
  }
}
int main() {
  for (int i = 0; i <= 9; i++) {
    num[i][0] = i;
    for (int j = 1; j < 10; j++) {
      num[i][j] = num[i][j - 1] + work(i + j);
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    ans = "99999999999999999999999999999";
    for (int i = 0; i < 10; i++) {
      if (n < num[i][k] || (n - num[i][k]) % (k + 1) != 0) continue;
      temp = "";
      if (i + k >= 10)
        s((n - num[i][k]) / (k + 1), 0);
      else
        s((n - num[i][k]) / (k + 1), 1);
      temp += i + '0';
      if (ans.size() > temp.size())
        ans = temp;
      else if (ans.size() == temp.size())
        ans = min(ans, temp);
    }
    if (ans == "99999999999999999999999999999")
      cout << "-1" << endl;
    else
      cout << ans << endl;
  }
}
