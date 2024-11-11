#include <bits/stdc++.h>
using namespace std;
string str;
long long sol(long long l, long long r, bool keky) {
  long long ans = 0, ymn = 0;
  if (!keky) {
    for (long long i = l; i < r; i += 2) {
      if (str[i] == '+') {
        if (ymn != 0) {
          ans += ymn;
          ymn = 0;
        } else {
          ans += str[i - 1] - '0';
        }
      } else {
        if (ymn == 0) {
          ymn = str[i - 1] - '0';
          ymn *= str[i + 1] - '0';
        } else {
          ymn *= str[i + 1] - '0';
        }
      }
    }
    if (ymn != 0) {
      ans += ymn;
    } else {
      ans += str[r - 1] - '0';
    }
  } else {
    for (long long i = 1; i < l; i += 2) {
      if (str[i] == '+') {
        if (ymn != 0) {
          ans += ymn;
          ymn = 0;
        } else {
          ans += str[i - 1] - '0';
        }
      } else {
        if (ymn == 0) {
          ymn = str[i - 1] - '0';
          ymn *= str[i + 1] - '0';
        } else {
          ymn *= str[i + 1] - '0';
        }
      }
    }
    if (ymn == 0) {
      ymn = str[l - 1] - '0';
    }
    ymn *= sol(l + 2, r, false);
    for (long long i = r; i < str.size(); i += 2) {
      if (str[i] == '+') {
        if (ymn != 0) {
          ans += ymn;
          ymn = 0;
        } else {
          ans += str[i - 1] - '0';
        }
      } else {
        if (ymn == 0) {
          ymn = str[i - 1] - '0';
          ymn *= str[i + 1] - '0';
        } else {
          ymn *= str[i + 1] - '0';
        }
      }
    }
    ans += ymn;
  }
  return ans;
}
int main() {
  cin >> str;
  str = "1*" + str + "*1";
  vector<long long> left;
  vector<long long> right(1);
  for (long long i = 3; i < str.size(); i += 2) {
    if (str[i] == '*') {
      if (str[i - 2] == '*') {
        continue;
      } else {
        right.push_back(i);
      }
    } else {
      if (str[i - 2] == '*') {
        left.push_back(i - 2);
      } else {
        continue;
      }
    }
  }
  long long ans = -1;
  for (long long i = 0; i < left.size(); i++) {
    for (long long j = i + 1; j < right.size(); j++) {
      ans = max(ans, sol(left[i], right[j], true));
    }
  }
  ans = max(ans, sol(1, 1, true));
  cout << ans;
  return 0;
}
