#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<pair<char, long>> A;
  long n = s.size();
  pair<char, long> a = make_pair(s[0], 1);
  for (long i = 1; i < n; i++) {
    if ((s[i] != s[i - 1]) || (i == (n - 1))) {
      if (s[i] == s[i - 1]) {
        a.second++;
      }
      A.push_back(a);
      a.first = s[i];
      a.second = 1;
      if ((s[i] != s[i - 1]) && (i == (n - 1))) {
        A.push_back(a);
      }
    } else {
      a.second++;
    }
  }
  long k = A.size();
  if (k == 1) {
    cout << 0;
    return 0;
  }
  long steps = 0;
  while (1 == 1) {
    long m = 123456789;
    long t = A.size();
    for (long i = 0; i < t; i++) {
      long att = (A[i].second + 1) / 2;
      if ((i == 0) || ((i + 1) == t)) {
        att = A[i].second;
      }
      if (att < m) {
        m = att;
      }
    }
    vector<pair<char, long>> B;
    for (long i = 0; i < t; i++) {
      if ((i == 0) || (i == (t - 1))) {
        A[i].second -= m;
      } else {
        A[i].second -= 2 * m;
      }
      if (A[i].second > 0) {
        long k = B.size();
        if (k == 0) {
          B.push_back(A[i]);
        } else {
          if (A[i].first != B[k - 1].first) {
            B.push_back(A[i]);
          } else {
            B[k - 1].second += A[i].second;
          }
        }
      }
    }
    A = B;
    steps += m;
    if (A.size() <= 1) {
      break;
    }
  }
  cout << steps;
  return 0;
}
