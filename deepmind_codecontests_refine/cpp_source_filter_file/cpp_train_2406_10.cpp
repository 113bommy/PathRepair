#include <bits/stdc++.h>
using namespace std;
string a, l, r;
string lZ, RZ;
long lenA, lenL, lenR;
long long dp[1000004] = {};
long long suff[1000004] = {};
long z1[1000004] = {};
long z2[1000004] = {};
int constructZArray(string s, long z[]) {
  pair<long, long> lr, temp;
  long k;
  z[0] = s.length();
  lr = make_pair(0, 0);
  long i = 1, start, index;
  while (i != s.length()) {
    if (i > lr.second) {
      start = 0;
      index = i;
      pair<long, long> temp = make_pair(-1, -1);
      if (s[start] == s[index]) {
        temp.first = index;
        temp.second = index;
        for (long i = index + 1; i < s.length(); i++) {
          if (s[i - (index - start)] == s[i])
            temp.second++;
          else
            break;
        }
      }
      if (temp.first == -1)
        z[i] = 0;
      else {
        lr = temp;
        z[i] = lr.second - lr.first + 1;
      }
    } else {
      k = i - lr.first;
      if (z[k] < lr.second - i + 1)
        z[i] = z[k];
      else {
        lr.first = i;
        start = lr.second - i + 1;
        index = lr.second + 1;
        pair<long, long> temp = make_pair(-1, -1);
        if (s[start] == s[index]) {
          temp.first = index;
          temp.second = index;
          for (long i = index + 1; i < s.length(); i++) {
            if (s[i - (index - start)] == s[i])
              temp.second++;
            else
              break;
          }
        }
        if (temp.second != -1) lr.second = temp.second;
        z[i] = lr.second - lr.first + 1;
      }
    }
    i++;
  }
  return 1;
}
int comp(string &a, string &b, long start, long end, long z[], long len) {
  long la = end - start, lower_bound = b.length();
  if (la > lower_bound)
    return 0;
  else if (lower_bound > la)
    return 1;
  else {
    if (z[len + 1 + start] == len) return 3;
    if (a[start + z[len + 1 + start]] > b[z[len + 1 + start]])
      return 0;
    else
      return 1;
  }
  return 3;
}
long findMinL(long pos, long start, long end) {
  long long temp;
  if (start == end) {
    temp = comp(a, l, pos, start + 1, z1, lenL);
    return ((temp == 0 || temp == 3) ? start : -1);
  }
  long mid = (end + start) / 2;
  temp = comp(a, l, pos, mid + 1, z1, lenL);
  return ((temp == 0 || temp == 3) ? findMinL(pos, start, mid)
                                   : findMinL(pos, mid + 1, end));
}
long findMaxR(long pos, long start, long end) {
  long long temp;
  if (start == end) {
    temp = comp(a, r, pos, start + 1, z2, lenR);
    return ((temp == 1 || temp == 3) ? start : -1);
  }
  long mid = (end + start + 1) / 2;
  temp = comp(a, r, pos, mid + 1, z2, lenR);
  return ((temp == 1 || temp == 3) ? findMaxR(pos, mid, end)
                                   : findMaxR(pos, start, mid - 1));
}
long finddp(long pos) {
  long L, R;
  if (a[pos] == '0' && l[0] == '0') {
    L = pos;
    R = pos;
  } else if (a[pos] == '0' && l[0] != '0') {
    L = -1;
    R = -1;
  } else {
    L = findMinL(pos, pos, a.length() - 1);
    R = findMaxR(pos, pos, a.length() - 1);
  }
  if (L != -1 && R != -1) {
    dp[pos] = (suff[L + 1] - suff[R + 2]) % 998244353;
  }
  suff[pos] = (suff[pos + 1] + dp[pos]);
}
int main() {
  cin >> a;
  cin >> l;
  cin >> r;
  lenA = a.length();
  lenL = l.length();
  lenR = r.length();
  string lZ = l + '&' + a;
  string rZ = r + '&' + a;
  memset(dp, 0, sizeof(dp));
  constructZArray(lZ, z1);
  constructZArray(rZ, z2);
  dp[a.length()] = 1;
  suff[a.length()] = 1;
  suff[a.length() + 1] = 0;
  for (long i = a.length() - 1; i >= 0; i--) finddp(i);
  cout << dp[0] << endl;
}
