#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n, m;
string str1;
string str2;
long long curcnt = 0;
char curchar = '$';
long long ans = 0;
char fchar;
long long fcnt;
char lchar;
long long lcnt;
void getZarr(string str, long long Z[]) {
  long long n = str.length();
  long long L, R, k;
  L = R = 0;
  for (long long i = 1; i < n; ++i) {
    if (i > R) {
      L = R = i;
      while (R < n && str[R - L] == str[R]) R++;
      Z[i] = R - L;
      R--;
    } else {
      k = i - L;
      if (Z[k] < R - i + 1)
        Z[i] = Z[k];
      else {
        L = i;
        while (R < n && str[R - L] == str[R]) R++;
        Z[i] = R - L;
        R--;
      }
    }
  }
}
void search(string text, string pattern) {
  string concat = pattern + "$" + text;
  long long l = concat.length();
  long long Z[l];
  getZarr(concat, Z);
  char llchar = '$';
  long long llnum = 0;
  long long cur = 0;
  for (long long i = 0; i < 100; ++i) concat += '$';
  for (long long i = 0; i < l; ++i) {
    if (isalpha(concat[i]) || concat[i] == '$') {
      llchar = concat[i];
      llnum = cur;
      cur = 0;
    } else {
      cur *= 10;
      cur += concat[i] - '0';
    }
    if (Z[i] == pattern.length()) {
      if (llchar != fchar) {
        continue;
      }
      if (llnum < fcnt) {
        continue;
      }
      long long lllol = i + Z[i];
      long long num = 0;
      while (isdigit(concat[lllol]) && lllol < l) {
        num *= 10;
        num += concat[lllol] - '0';
        lllol++;
      }
      char tmp = concat[lllol];
      if (tmp != lchar) {
        continue;
      }
      if (num < lcnt) {
        continue;
      }
      ++ans;
    }
  }
}
vector<pair<char, long long> > arr1;
vector<pair<char, long long> > arr2;
void brute() {
  if (arr2.size() == 1) {
    for (auto it : arr1) {
      if (it.first == arr2[0].first) {
        ans += max(0LL, it.second - arr2[0].second + 1);
      }
    }
  } else {
    char lst = '$';
    long long cnt = 0;
    for (auto it : arr1) {
      if (lst == arr2[0].first && it.first == arr2[1].first) {
        ans += (cnt >= arr2[0].second) && (it.second >= arr2[1].second);
      }
      lst = it.first;
      cnt = it.second;
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) {
    long long tmp;
    char x1;
    char x2;
    cin >> tmp >> x1 >> x2;
    if (x2 == curchar) {
      curcnt += tmp;
    } else {
      if (curchar != '$') {
        str1 += to_string(curcnt);
        str1 += curchar;
        arr1.emplace_back(make_pair(curchar, curcnt));
      }
      curchar = x2;
      curcnt = tmp;
    }
  }
  str1 += to_string(curcnt);
  str1 += curchar;
  arr1.emplace_back(make_pair(curchar, curcnt));
  curcnt = 0;
  curchar = '$';
  bool ok = 0;
  for (long long i = 1; i <= m; ++i) {
    long long tmp;
    char x1;
    char x2;
    cin >> tmp >> x1 >> x2;
    if (x2 == curchar) {
      curcnt += tmp;
    } else {
      if (curchar != '$') {
        if (ok) {
          str2 += to_string(curcnt);
          str2 += curchar;
        } else {
          ok = 1;
          fchar = curchar;
          fcnt = curcnt;
        }
        arr2.emplace_back(make_pair(curchar, curcnt));
      }
      curchar = x2;
      curcnt = tmp;
    }
  }
  if (ok) {
    str2 += to_string(curcnt);
    str2 += curchar;
    lchar = curchar;
    lcnt = curcnt;
  } else {
    ok = 1;
    fchar = curchar;
    fcnt = curcnt;
  }
  arr2.emplace_back(make_pair(curchar, curcnt));
  if (arr2.size() <= 2) {
    brute();
    return 0;
  }
  str2.pop_back();
  while (isdigit(str2.back())) {
    str2.pop_back();
  }
  search(str1, str2);
  cout << ans;
}
