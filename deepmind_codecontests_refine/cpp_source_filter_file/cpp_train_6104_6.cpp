#include <bits/stdc++.h>
using namespace std;
long long q, n, k;
long long l[100007] = {};
string s0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string sp0 = "What are you doing while sending \"";
string sp1 = "\"? Are you busy? Will you send \"";
string sp2 = "\"?";
long long lengthOfF(long long n) {
  if (n == 0) {
    return 75;
  }
  if (l[n] != 0) {
    return l[n];
  }
  long long x = lengthOfF(n - 1);
  if (x >= 1e18) {
    l[n] = 1e19;
  } else {
    l[n] = 2 * lengthOfF(n - 1) + 68;
  }
  return l[n];
}
char charOfF(long long n, long long k) {
  if (n == 0) {
    return s0[k - 1];
  }
  if (1 <= k && k <= 34) {
    return sp0[k - 1];
  }
  if (35 <= k && k <= 34 + l[n - 1]) {
    return charOfF(n - 1, k - 34);
  }
  if (35 + l[n - 1] <= k && k <= 34 + l[n - 1] + 32) {
    return sp1[k - 34 - l[n - 1] - 1];
  }
  if (l[n] >= k && k >= l[n] - 1) {
    return sp2[k - (l[n] - 1)];
  }
  if (34 + l[n - 1] + 32 + 1 <= k && k <= l[n] - 2) {
    return charOfF(n - 1, k - 34 - l[n - 1] - 32);
  }
  return '^';
}
int main() {
  l[0] = 75;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> n >> k;
    if (k > lengthOfF(n)) {
      cout << '.';
    } else {
      cout << charOfF(n, k);
    }
  }
  cout << endl;
}
