#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n1, lol[2222], baga = 0, ih = 0, a[111], n, t, s = 0, d, f;
  string st[111];
  map<string, int> mp;
  map<string, int>::iterator it;
  cin >> n >> n1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int j = n;
  for (int i = 1; i <= n1; i++) {
    cin >> st[i];
    mp[st[i]]++;
  }
  int i2 = 1;
  for (it = mp.begin(); it != mp.end(); it++) {
    lol[i2] = it->second;
    i2++;
  }
  sort(lol, lol + i2);
  for (int i = i2 - 1; i > 0; i--) {
    ih = ih + a[j] * lol[i];
    j--;
  }
  j = 1;
  for (int i = i2 - 2; i > 0; i--) {
    baga = baga + a[j] * lol[i];
    j++;
  }
  cout << baga << " " << ih;
  return 0;
}
