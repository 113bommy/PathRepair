#include <bits/stdc++.h>
using namespace std;
void prepareIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(std::numeric_limits<double>::max_digits10);
}
struct HASH {
  size_t operator()(const pair<long long int, long long int>& x) const {
    return hash<long long>()(x.first ^ (x.second) << 32);
  }
};
const long long int MOD = 1e9 + 7;
const long long int N = 1e5 + 5;
bool isPrime(long long int num) {
  if (num == 1) {
    return false;
  }
  for (long long int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
bool found(string& s, vector<long long int>& a) {
  if (s.length() < a.size()) {
    return false;
  }
  long long int idx = 0;
  for (long long int dig : a) {
    bool f = false;
    while (idx < s.length()) {
      long long int d = s[idx] - '0';
      if (d == dig) {
        f = true;
        idx++;
        break;
      }
      idx++;
    }
    if (!f) {
      return false;
    }
  }
  return true;
}
int main() {
  prepareIO();
  long long int t = 1;
  cin >> t;
  for (long long int Case = 1; Case <= t; Case++) {
    long long int k;
    cin >> k;
    string s;
    cin >> s;
    map<long long int, long long int> ct;
    bool nonPrimeFound = false;
    long long int num = -1;
    for (long long int i = 0; i < k; i++) {
      long long int dig = s[i] - '0';
      if (isPrime(dig)) {
        ct[dig]++;
      } else {
        nonPrimeFound = true;
        num = dig;
        break;
      }
    }
    if (nonPrimeFound) {
      cout << 1 << "\n";
      cout << num << "\n";
    } else {
      if (ct.count(2) > 0 && ct[2] >= 2) {
        cout << "2\n22\n";
      } else if (ct.count(3) > 0 && ct[3] >= 2) {
        cout << "2\n33\n";
      } else if (ct.count(5) > 0 && ct[5] >= 2) {
        cout << "2\n55\n";
      } else if (ct.count(7) > 0 && ct[7] >= 2) {
        cout << "2\n77\n";
      } else {
        vector<long long int> a = {2, 3, 5, 7};
        long long int numDig = LLONG_MAX, ans;
        for (long long int i = 1; i < 16; i++) {
          bitset<4> b(i);
          vector<long long int> st;
          for (long long int j = 0; j < 4; j++) {
            if (b[j]) {
              st.push_back(a[j]);
            }
          }
          sort(st.begin(), st.end());
          bool f = false;
          do {
            long long int num = 0;
            for (long long int dig : st) {
              num = (num * 10) + dig;
            }
            if (!isPrime(num)) {
              f = found(s, st);
              if (f) {
                break;
              }
            }
          } while (next_permutation(st.begin(), st.end()));
          if (f) {
            if (st.size() < numDig) {
              numDig = st.size();
              long long int num = 0;
              for (long long int dig : st) {
                num = (num * 10) + dig;
              }
              ans = num;
            }
          }
        }
        cout << numDig << "\n" << ans << "\n";
      }
    }
  }
  return 0;
}
