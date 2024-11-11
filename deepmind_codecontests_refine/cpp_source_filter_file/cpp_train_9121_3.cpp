#include <bits/stdc++.h>
using namespace ::std;
const long long maxn = 1e5 + 500;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 500;
long long len[maxn];
string s =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string t1 = "What are you doing while sending \"";
string t2 = "\"? Are you busy? Will you send \"";
string t3 = "\"?";
char f(long long n, long long k) {
  if (n == 0) {
    return s[k];
  }
  if (k < t1.size()) {
    return t1[k];
  }
  k -= t1.size();
  if (k < len[n - 1]) {
    return f(n - 1, k);
  }
  k -= len[n - 1];
  if (k < t2.size()) {
    return t2[k];
  }
  k -= t2.size();
  if (k < len[n - 1]) {
    return f(n - 1, k);
  }
  k -= len[n - 1];
  return t3[k];
}
int main() {
  len[0] = s.size();
  for (long long i = 1; i < 1000; i++) {
    len[i] = 2 * len[i - 1] + (t1.size() + t2.size() + t3.size());
    if (len[i] > 1e18) {
      len[i] = 1e18;
    }
  }
  long long q;
  cin >> q;
  for (long long qw = 0; qw < q; qw++) {
    long long n, k;
    cin >> n >> k;
    k--;
    if (len[n] <= k) {
      cout << '.';
    } else {
      cout << f(n, k);
    }
  }
}
