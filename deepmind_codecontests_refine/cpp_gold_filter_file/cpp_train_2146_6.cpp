#include <bits/stdc++.h>
using namespace std;
long long tri(int num) {
  long long res = 0;
  for (int i = 1; i < num; i++) res += i;
  return res;
}
long long solve() {
  int n, l[100001];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i];
  l[n] = l[n - 1] - 1;
  long long res = n, cur = l[0], con = 1;
  for (int i = 1; i < n + 1; i++) {
    if (cur == l[i]) {
      con++;
    } else {
      if (con > 1) res += tri(con);
      cur = l[i];
      con = 1;
    }
  }
  return res;
}
int main(int argc, char *argv[]) {
  cout << solve() << endl;
  return 0;
}
