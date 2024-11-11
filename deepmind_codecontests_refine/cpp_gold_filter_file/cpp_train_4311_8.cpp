#include <bits/stdc++.h>
using namespace std;
string s;
long long cnt[200];
int main() {
  cin >> s;
  long long n = s.size();
  for (int i = 0; i < 200; i++) cnt[i] = 0;
  for (int i = 0; i < n; i++) ++cnt[s[i]];
  long long len;
  cin >> len;
  long long ll = 1, rr = n + 1;
  while (ll < rr) {
    long long mid = (ll + rr) / 2;
    long long need = 0;
    for (int i = 97; i <= 122; i++) need += (cnt[i] + mid - 1) / mid;
    if (need <= len)
      rr = mid;
    else
      ll = mid + 1;
  }
  if (ll == n + 1) {
    cout << -1;
    return 0;
  }
  int mid = ll;
  cout << mid << endl;
  int need = 0;
  for (int i = 97; i <= 122; i++) {
    int needhere = (cnt[i] + mid - 1) / mid;
    for (int j = 0; j < needhere; j++) {
      need++;
      cout << (char)i;
    }
  }
  while (need < len) {
    cout << 'a';
    need++;
  }
  return 0;
}
