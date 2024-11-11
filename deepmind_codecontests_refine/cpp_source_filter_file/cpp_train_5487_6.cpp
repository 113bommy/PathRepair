#include <bits/stdc++.h>
#pragma comment(linker, "/stack:100000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int N = 1e3 + 5;
const int MOD = 998244373;
vector<string> t;
vector<string> my[200];
bool cmp(string a, string b) { return a.size() < b.size(); }
bool check(int a, int b) {
  string s1 = my[a][0];
  string s2 = my[b][0];
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] == s1[0]) {
      int k = 0;
      for (int j = i; j < s2.size(); j++) {
        if (s2[j] == s1[k])
          k++;
        else
          break;
        if (k == s1.size()) return true;
      }
    }
  }
  return false;
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int sz = (int)s.size();
    my[sz].push_back(s);
    t.push_back(s);
  }
  sort(t.begin(), t.end(), cmp);
  for (int i = 1; i <= 100; i++) {
    if (my[i].size() > 1) {
      for (int k = 0; k <= my[i].size() - 1; k++) {
        for (int j = k + 1; j < my[i].size() - 1; j++) {
          if (my[i][k] != my[i][j]) {
            cout << "NO" << endl;
            return 0;
          }
        }
      }
    }
  }
  vector<int> te;
  for (int i = 1; i <= 100; i++) {
    if (my[i].size() > 0) te.push_back(i);
  }
  if (te.size() == 1) {
    cout << "YES" << endl;
    int len = te[0];
    for (int i = 0; i < my[len].size(); i++) cout << my[len][i] << endl;
  } else {
    for (int i = 1; i < te.size(); i++) {
      if (!check(te[i - 1], te[i])) {
        cout << "NO" << endl;
        return 0;
      }
    }
    cout << "YES" << endl;
    for (auto s : t) cout << s << endl;
  }
  return 0;
}
void bef0re_submit() {
  puts("Make sure the algorithm is right!");
  puts("LONG LONG!!!");
  puts("n==0?1?2?3?");
  puts("Make sure output format is right/// Yes??YES  (%.20LF)???");
  puts("if all meet,run with special situation!!!");
  puts("I confirm that I have done all above");
  puts("If u know brute,consider fast,binary(log) or tree?");
}
