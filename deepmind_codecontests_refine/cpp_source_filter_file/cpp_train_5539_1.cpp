#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    long long k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (k > i - cnt) {
          swap(s[i], s[cnt]);
          k -= i - cnt;
        } else {
          swap(s[i], s[i - k]);
          break;
        }
        cnt++;
      }
    }
    cout << s << endl;
  }
}
