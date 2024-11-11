#include <bits/stdc++.h>
using namespace std;
int n, q, l, r;
string s;
void run(int l, int r) {
  string ss = "";
  int a[15] = {0};
  int cp = 0, dp = 1;
  for (int i = l - 1; i < r; i++) ss += s[i];
  while (true) {
    if (ss[cp] >= '0' && ss[cp] <= '9') {
      int digit = ss[cp] - '0';
      a[digit]++;
      if (digit)
        ss[cp]--;
      else {
        ss.erase(cp, 1);
        cp--;
      }
      if (dp)
        cp++;
      else
        cp--;
      if (cp < 0 || cp >= (int)ss.length()) break;
    } else {
      if (ss[cp] == '>')
        dp = 1;
      else if (ss[cp] == '<')
        dp = 0;
      if (dp)
        cp++;
      else
        cp--;
      if (cp < 0 || cp >= (int)ss.length()) break;
      if (ss[cp] == '>' || ss[cp] == '<') {
        if (dp) {
          ss.erase(cp - 1, 1);
          cp--;
        } else
          ss.erase(cp + 1, 1);
      }
    }
  }
  for (int i = 0; i < 10; i++) cout << a[i] << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> q;
  cin >> s;
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    run(l, r);
  }
  return 0;
}
