#include <bits/stdc++.h>
using namespace std;
int cnt[200005];
bool input[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> input[i];
  int cn = 0;
  cn = 0;
  for (int i = n - 1; i >= 0; i--) {
    cnt[i] += cn;
    cn += !input[i];
  }
  long long res = 0;
  for (int i = 0; i < n; i++)
    if (input[i]) res += cnt[i];
  cout << res << endl;
}
