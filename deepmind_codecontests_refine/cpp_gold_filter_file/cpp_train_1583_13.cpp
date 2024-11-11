#include <bits/stdc++.h>
using namespace std;
template <class T>
void pp(T v) {
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
    cout << *it << ' ';
  cout << endl;
}
template <class T>
void pp(T v, int n) {
  for (int i = 0; i < (int)n; i++) cout << v[i] << ' ';
  cout << endl;
}
const int INF = 1 << 28;
const double EPS = 1.0e-9;
static const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int main(void) {
  string s;
  cin >> s;
  int N = s.size();
  map<char, int> c_cnt;
  for (int i = 0; i < (int)N; i++) c_cnt[s[i]]++;
  vector<pair<int, char> > rev_c_cnt;
  for (map<char, int>::iterator it = c_cnt.begin(); it != c_cnt.end(); it++) {
    rev_c_cnt.push_back(make_pair(it->second, it->first));
  }
  sort(rev_c_cnt.rbegin(), rev_c_cnt.rend());
  vector<int> prime;
  for (int i = 2; i <= N; i++) {
    bool ok = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        ok = false;
        break;
      }
    }
    if (ok) prime.push_back(i);
  }
  set<int> group;
  for (int i = 2; i <= N; i += 2) group.insert(i);
  for (int i = 1; i < prime.size(); i++) {
    if (prime[i] * 2 <= N) {
      for (int j = prime[i]; j <= N; j += prime[i]) {
        group.insert(j);
      }
    }
  }
  if (rev_c_cnt[0].first >= group.size()) {
    cout << "YES" << endl;
    string ans(N, ' ');
    for (__typeof((group).begin()) it = (group).begin(); it != (group).end();
         ++it)
      ans[*it - 1] = rev_c_cnt[0].second;
    string rem(rev_c_cnt[0].first - group.size(), rev_c_cnt[0].second);
    for (int i = 1; i < rev_c_cnt.size(); i++) {
      string r(rev_c_cnt[i].first, rev_c_cnt[i].second);
      rem += r;
    }
    vector<char> rem_char((rem).begin(), (rem).end());
    for (int i = 0; i < (int)ans.size(); i++) {
      if (ans[i] == ' ') {
        ans[i] = rem_char.back();
        rem_char.pop_back();
      }
    }
    cout << ans << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
