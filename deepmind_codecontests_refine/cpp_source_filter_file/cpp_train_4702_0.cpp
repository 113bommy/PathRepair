#include <bits/stdc++.h>
using namespace std;
long long num[100010];
int vis[100010] = {0};
char a[10], b[100010];
vector<long long> f;
vector<long long> e;
int flag = 0;
long long maxn = 0;
long long T;
long long res = 0;
long long solve(long long time) {
  long long tt = 0;
  long long add = 0;
  long long sum = 0;
  while (1) {
    cin >> a;
    T--;
    if (a[0] == 'f') {
      cin >> tt;
      long long ttt = tt * time;
      if (ttt > maxn) {
        ttt = maxn;
      }
      sum += solve(ttt);
    } else if (a[0] == 'a') {
      add++;
    } else {
      return sum + add * time;
    }
    if ((sum + add * time) > maxn) {
      flag = 1;
      return 0;
    }
    if (!T) {
      res = sum + add * time;
      return 0;
    }
  }
}
int main() {
  maxn = pow(2, 32) - 1;
  cin >> T;
  solve(1);
  if (flag)
    cout << "OVERFLOW!!!" << endl;
  else
    cout << res << endl;
  return 0;
}
