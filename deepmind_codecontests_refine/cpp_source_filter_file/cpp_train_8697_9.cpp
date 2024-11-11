#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
bool st[1000000], sttotal;
int main() {
  long long n;
  cin >> n;
  ;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 1)
      st[i] = false;
    else
      st[i] = true;
    sttotal = st[i] xor st[i - 1];
    if (sttotal == true)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
  return 0;
}
