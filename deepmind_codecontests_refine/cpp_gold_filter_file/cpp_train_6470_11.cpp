#include <bits/stdc++.h>
using namespace std;
const int N = (int)(1e6 + 5);
const int LOG = (int)(20);
int n, cnt;
char s[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> s + 1;
  for (int i = 1; i <= n - 10; i++) {
    if (s[i] == '8')
      cnt++;
    else
      cnt--;
  }
  if (cnt >= 0)
    cout << "YES";
  else
    cout << "NO";
}
