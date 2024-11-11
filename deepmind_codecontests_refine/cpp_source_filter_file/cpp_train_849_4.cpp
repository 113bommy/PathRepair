#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  long long int a[n];
  long long int pos = 1, neg = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0)
      a[i] = 1;
    else
      a[i] = -1;
    if (i > 0) a[i] *= a[i - 1];
    if (a[i] == 1)
      pos++;
    else
      neg++;
  }
  long long int totneg = (pos * neg);
  long long int tot = (n * (n + 1)) / 2;
  long long int totpos = tot - totneg;
  cout << totneg << " " << totpos;
}
