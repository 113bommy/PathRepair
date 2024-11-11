#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a, cnt = 0, cnt1 = 0;
  while (n--) {
    cin >> a;
    if (a == 5)
      cnt1++;
    else
      cnt++;
  }
  if (cnt == 0)
    cout << "-1";
  else {
    if (cnt1 / 9 == 0)
      cout << "0";
    else {
      cnt1 = (cnt1 / 9) * 9;
      for (long long i = 0; i < cnt1; i++) cout << "5";
      for (long long i = 0; i < cnt; i++) cout << "0";
    }
  }
  return 0;
}
