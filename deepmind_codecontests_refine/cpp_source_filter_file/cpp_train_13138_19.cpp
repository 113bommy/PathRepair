#include <bits/stdc++.h>
using namespace std;
const long long maxsz = 1e6 + 10;
char s[maxsz];
const long long p1 = 1e9 + 321;
const long long base = 1013;
long long pws1[maxsz];
long long preff[maxsz];
void build(long long len) {
  pws1[0] = 1;
  preff[0] = 0;
  for (int i = 1; i <= len; i++) {
    pws1[i] = (pws1[i - 1] * base) % p1;
    preff[i] = (preff[i - 1] * base + (s[i - 1] - 'a' + 1)) % p1;
  }
}
long long getKey(long long l, long long r) {
  long long len = r - l + 1;
  long long res = (preff[l + len] - preff[l] * pws1[len]) % p1;
  if (res < 0) res += p1;
  return res;
}
bool isSame(long long len, long long len_str) {
  long long num1 = getKey(0, len - 1);
  long long inv_l = len_str - len;
  long long num2 = getKey(inv_l, len_str - 1);
  if (num1 == num2) return true;
  return false;
}
vector<long long> nums;
bool find_str(long long hash_num, long long len, long long len_str) {
  for (int L = 1; L + len < len_str; L++) {
    long long R = L + len - 1;
    long long num1 = getKey(L, R);
    if (num1 == hash_num) return true;
  }
  return false;
}
int main() {
  scanf("%s", s);
  long long len = strlen(s);
  build(len);
  for (int r = 2; r < len - 1; r++) {
    if (isSame(r, len)) nums.push_back(r);
  }
  long long lo = 0, hi = nums.size();
  long long p = -1;
  while (lo < hi) {
    long long mi = (lo + hi) / 2;
    long long tst = nums[mi];
    long long prf = getKey(0, tst - 1);
    if (find_str(prf, tst, len))
      lo = mi + 1, p = max(tst, p);
    else
      hi = mi;
  }
  if (p != -1)
    for (int i = 0; i < p; i++) cout << s[i];
  else
    cout << "Just a legend";
  cout << endl;
}
