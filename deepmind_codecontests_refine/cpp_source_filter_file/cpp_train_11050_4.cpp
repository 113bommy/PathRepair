#include <bits/stdc++.h>
using namespace std;
const long long INF = 2000000000;
const long long modulo = 1000000007;
long long phash[3000];
long long step[3000];
long long subhash(int s, int f) {
  if (s == 0) return phash[f];
  return phash[f] - phash[s - 1] * step[f - s + 1];
}
int main() {
  long long q = 9241;
  string t, start, fin;
  cin >> t >> start >> fin;
  int n = t.length();
  int slen = start.length();
  long long shash = start[0];
  for (int i = 1; i < slen; i++) shash = shash * q + start[i];
  int finlen = fin.length();
  long long finhash = fin[0];
  for (int i = 1; i < slen; i++) finhash = finhash * q + fin[i];
  phash[0] = t[0];
  for (int i = 1; i < n; i++) phash[i] = phash[i - 1] * q + t[i];
  step[0] = 1;
  for (int i = 1; i <= n; i++) step[i] = step[i - 1] * q;
  int ans = 0;
  vector<long long> hashes;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      int len = j - i + 1;
      if (len < max(slen, finlen)) continue;
      if (subhash(i, i + slen - 1) == shash &&
          subhash(j - finlen + 1, j) == finhash)
        hashes.push_back(subhash(i, j));
    }
  if (hashes.size() == 0) {
    cout << 0;
    return 0;
  }
  sort(hashes.begin(), hashes.end());
  int p = hashes.size();
  ans = 1;
  for (int i = 1; i < p; i++)
    if (hashes[i] != hashes[i - 1]) ans++;
  cout << ans;
}
