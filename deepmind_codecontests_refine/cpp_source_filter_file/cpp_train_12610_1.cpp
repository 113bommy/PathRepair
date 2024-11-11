#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long zero = 0, one = 0, two = 0;
  vector<long long> z, o, t;
  for (long long i = 0; i < n; i++) {
    if (s[i] - '0' == 0) {
      zero++;
      z.push_back(i);
    } else if (s[i] - '0' == 1) {
      one++;
      o.push_back(i);
    } else {
      two++;
      t.push_back(i);
    }
  }
  if (zero == one and one == two) {
    cout << s;
    return;
  }
  long long cnt = n / 3;
  if (zero > cnt && one > cnt) {
    for (long long i = n - 1; i >= 0; i--) {
      if (s[i] == '0' && zero > cnt) {
        s[i] = '2';
        zero--;
      } else if (s[i] == '1' && one > cnt) {
        s[i] = '2';
        one--;
      }
    }
    cout << s;
  } else if (zero > cnt && two > cnt) {
    long long i = z.size() - 1;
    while (zero > cnt) {
      s[z[i]] = '1';
      i--;
      zero--;
    }
    i = 0;
    while (two > cnt) {
      s[t[i]] = '1';
      i++;
      two--;
    }
    cout << s;
  } else if (one > cnt and two > cnt) {
    long long i = 0;
    while (one > cnt) {
      s[o[i]] = '0';
      i++;
      one--;
    }
    i = 0;
    while (two > cnt) {
      s[t[i]] = '1';
      i++;
      two--;
    }
    cout << s;
  } else if (zero > cnt) {
    long long i = z.size() - 1;
    while (two < cnt) {
      s[z[i]] = '2';
      two++;
      i--;
    }
    while (one < cnt) {
      s[z[i]] = '1';
      one++;
      i--;
    }
    cout << s;
  } else if (one > cnt) {
    long long i = 0;
    while (zero < cnt) {
      s[o[i]] = '0';
      zero++;
      i++;
    }
    i = o.size() - 1;
    while (two < cnt) {
      s[o[i]] = '2';
      two++;
      i--;
    }
    cout << s;
  } else if (two > cnt) {
    long long i = 0;
    while (zero < cnt) {
      s[t[i]] = '0';
      zero++;
      i++;
    }
    while (one < cnt) {
      s[t[i]] = '1';
      one++;
      i++;
    }
    cout << s;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
