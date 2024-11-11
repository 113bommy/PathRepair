#include <bits/stdc++.h>
using namespace std;
void proc() {}
void read() {}
short a[200005];
int main() {
  long long n;
  cin >> n;
  long long cnt = 0;
  long long ans = 0;
  bool flag = false;
  for (int i = int(1); i <= int(n); i++) {
    cin >> a[i];
    if (a[i]) {
      cnt++;
    } else
      ans = ans + cnt;
  }
  cout << ans << endl;
}
