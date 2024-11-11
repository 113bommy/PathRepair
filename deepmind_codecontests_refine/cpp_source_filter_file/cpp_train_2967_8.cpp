#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e6;
int ar[MAX];
bool pr[MAX];
string s;
void pre() {
  pr[0] = 1;
  pr[1] = 1;
  for (int i = 2; i * i < MAX; ++i) {
    if (!pr[i]) {
      for (int j = i * i; j < MAX; j += i) {
        pr[j] = 1;
      }
    }
  }
}
int ste(int n) {
  int x = 0;
  int r;
  s = "";
  while (n) {
    r = n % 10;
    s += (r + '0');
    n /= 10;
    ++x;
  }
  return x;
}
bool pal(int x) {
  int len = ste(x);
  for (int i = 0; i < len / 2; ++i)
    if (s[i] != s[len - i - 1]) return false;
  return true;
}
int main() {
  int p, q;
  pre();
  scanf("%d%d", &p, &q);
  int ispr = 0;
  int ispal = 0;
  int ans = -1;
  for (int i = 1; i < MAX; ++i) {
    if (!pr[i]) {
      ispr++;
    }
    if (pal(i)) {
      ispal++;
    }
    if (1LL * ispal * q >= 1LL * ispr * p) {
      ans = i;
    }
  }
  cout << ans << endl;
}
