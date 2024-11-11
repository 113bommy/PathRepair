#include <bits/stdc++.h>
const double eps = 1e-7, PI = 3.1415926;
const int N = 1e6;
using namespace std;
int n, m, k, a[N], sum1, sum2, sum3, mx = -1, mn = 1e9;
char c[N];
string s;
vector<int> vec;
int main() {
  cin >> k;
  cin >> s;
  n = s.size() / 3;
  for (int i = 0; i < s.size(); i++) {
    sum1 += (s[i] == '0');
    sum2 += (s[i] == '1');
    sum3 += (s[i] == '2');
  }
  if (sum1 < n) {
    for (int i = 0; i < s.size(); i++) {
      if (sum1 == n) break;
      if (s[i] == '2' && sum3 > n) {
        s[i] = '0';
        sum1++;
        sum3--;
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (sum1 == n) break;
      if (s[i] == '1' && sum2 > n) {
        s[i] = '0';
        sum1++;
        sum2--;
      }
    }
  }
  if (sum3 < n) {
    for (int i = s.size() - 1; i >= 0; i--) {
      if (sum3 == n) break;
      if (s[i] == '0' && sum1 > n) {
        sum1--;
        s[i] = '2';
        sum3++;
      } else if (s[i] == '1' && sum2 > n) {
        sum2--;
        s[i] = '2';
        sum3++;
      }
    }
  }
  if (sum2 < n) {
    for (int i = 0; i < s.size(); i++) {
      if (sum2 == n) break;
      if (s[i] == '2' && sum3 > n) {
        s[i] = '1';
        sum2++;
        sum3--;
      }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
      if (sum2 == n) break;
      if (s[i] == '0' && sum1 > n) {
        sum2++;
        s[i] = '1';
        sum1--;
      }
    }
  }
  cout << s;
  return 0;
}
