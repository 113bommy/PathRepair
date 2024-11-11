#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const double PI = acos(-1);
long long n, m, k;
string s;
int arr[255];
vector<string> vx;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  string s2;
  cin >> s >> s2;
  for (auto i : s) {
    arr[i] = 1;
  }
  int idx = -1;
  for (int j = 0; j < s2.size(); j++)
    if (s2[j] == '*') idx = j;
  string tmps2 = s2;
  if (idx != -1) tmps2.erase(idx, 1);
  int m;
  cin >> m;
  for (int x = 0; x < m; x++) {
    string t;
    cin >> t;
    int i = 0, j = 0;
    while (i < s2.size() && j < t.size()) {
      if (s2[i] == t[j]) {
        i++;
        j++;
        continue;
      }
      if (s2[i] == '?') {
        if (arr[t[j]]) {
          i++;
          j++;
        } else
          break;
      } else
        break;
    }
    if (i == s2.size() && j == t.size()) {
      cout << "YES" << endl;
    } else if (idx != -1) {
      int tmpi = s2.size() - 1;
      int tmpj = t.size() - 1;
      while (tmpi > i && tmpj >= j) {
        if (s2[tmpi] == t[tmpj]) {
          tmpi--;
          tmpj--;
        } else if (s2[tmpi] == '?') {
          if (arr[t[tmpj]]) {
            tmpi--;
            tmpj--;
          } else
            break;
        } else
          break;
      }
      if (tmpi == i) {
        bool ans = 1;
        for (; j <= tmpj; j++) {
          if (arr[t[j]]) ans = 0;
        }
        if (ans)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else
      cout << "NO" << endl;
  }
}
