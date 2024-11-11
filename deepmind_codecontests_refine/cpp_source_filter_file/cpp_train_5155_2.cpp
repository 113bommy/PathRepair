#include <bits/stdc++.h>
using namespace std;
long long int num[200005];
int main() {
  long long int cnt = 0, n, flag = 1, t = 1000000000, res = 0, rescnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    if (num[i] < t) {
      t = num[i];
      flag = i;
    }
  }
  res = t * n;
  flag = (flag + 1) % n;
  for (int i = 1; i <= n; i++) {
    cnt++;
    if (num[flag] == t) cnt = 0;
    rescnt = max(rescnt, cnt);
    flag = (flag + 1) % n;
  }
  cout << res + rescnt << endl;
  return 0;
}
