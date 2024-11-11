#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline ostream &operator<<(ostream &out, const vector<T> &v) {
  for (auto &it : v) out << it << ' ';
  return out;
}
template <typename T>
inline istream &operator>>(istream &in, vector<T> &v) {
  for (auto &it : v) in >> it;
  return in;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << p.first << ' ' << p.second << ' ';
  return out;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
inline istream &operator>(istream &in, T &p) {
  return in >> p;
}
template <typename T>
inline ostream &operator<(ostream &out, const T &p) {
  return out << p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin > n;
  vector<int> mas(n);
  cin > mas;
  for (int i = 0; i < n; i++) mas[i] -= i;
  vector<pair<long long, long long> > dp(n + 1, {1e+18, 1e+18});
  dp[0] = {0, -1e+18};
  for (int i = 0; i < n; i++) {
    multiset<int> m1, m2;
    long long sumL = 0, sumR = 0;
    for (int j = i + 1; j <= n; j++) {
      m1.insert(mas[j - 1]);
      sumL += mas[j - 1];
      while (m1.size() > m2.size() + 1 ||
             (!m1.empty() && !m2.empty() && *m1.rbegin() > *m2.rbegin()))
        sumL -= *m1.rbegin(), sumR += *m1.rbegin(), m2.insert(*m1.rbegin()),
            m1.erase(m1.find(*m1.rbegin()));
      long long lm, rm;
      if (m1.size() == m2.size()) {
        lm = *m1.rbegin();
        rm = *m2.begin();
      } else {
        lm = rm = *m1.rbegin();
      }
      if (dp[i].second > rm) continue;
      lm = max(lm, dp[i].second);
      long long an =
          dp[i].first + (m1.size() * lm - sumL) + (sumR - m2.size() * lm);
      if (an < dp[j].first)
        dp[j] = {an, lm};
      else if (an == dp[j].first)
        dp[j].second = min(dp[j].second, lm);
    }
  }
  cout < dp[n].first;
  return 0;
}
