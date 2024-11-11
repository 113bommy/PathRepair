#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void file_i_o();
void solve() {
  int n, k;
  cin >> n >> k;
  string s = to_string(n);
  string check = s;
  int m = s.length();
  while (true) {
    int i = 0;
    set<char> mark;
    while (i < m) {
      mark.insert(s[i]);
      if (mark.size() > k) {
        while (s[i] == '9') i--;
        s[i]++;
        break;
      } else if (s[i] > check[i]) {
        string ans = s.substr(0, i + 1);
        if (mark.size() < k) mark.insert(0);
        for (int j = i + 1; j < m; j++) {
          ans += *mark.begin();
        }
        cout << ans << "\n";
        return;
      }
      i++;
    }
    if (i == m) {
      cout << s << "\n";
      return;
    }
  }
}
void solve2() {
  int n, k;
  cin >> n >> k;
  string s = to_string(n);
  int m = s.length();
  map<char, int> mark;
  set<char> keep;
  int i = 0;
  while (i < m) {
    keep.insert(s[i]);
    mark[s[i]]++;
    if (keep.size() > k) {
      cout << "i"
           << " = " << i << endl;
      while (s[i] == '9') {
        mark[s[i]]--;
        if (mark[s[i]] == 0) mark.erase(s[i]);
        i--;
      }
      mark[s[i]]--;
      if (mark[s[i]] == 0) mark.erase(s[i]);
      s[i]++;
      mark[s[i]]++;
      keep.insert(s[i]);
      if (keep.size() < k) keep.insert('0');
      string ans = s.substr(0, i + 1);
      for (int j = i + 1; j < m; j++) {
        ans += *keep.begin();
      }
      cout << ans << "\n";
      return;
    }
    i++;
  }
  cout << n << "\n";
}
int32_t main(int32_t argc, char const *argv[]) {
  clock_t begin = clock();
  file_i_o();
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
