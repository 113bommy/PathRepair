#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  os << "{" << p.first << " " << p.second << "}";
  return os;
}
string rotate(vector<string>& v) {
  string ret = "";
  for (int i = 0; i < v.size(); ++i) ret += v[i];
  vector<string> tmp(v[0].size(), string(v.size(), ' '));
  for (int i = 0; i < v.size(); ++i)
    for (int j = 0; j < v[0].size(); ++j) tmp[j][v.size() - 1 - i] = v[i][j];
  v = tmp;
  return ret;
}
int main() {
  int a, b;
  cin >> a >> b;
  vector<string> arr(a);
  for (int i = 0; i < a; ++i) cin >> arr[i];
  vector<pair<int, pair<int, int> > > answ;
  int cnt = 0;
  for (int x = 1; x <= a; ++x) {
    for (int y = 1; y <= b; ++y) {
      if (a % x != 0 || b % y != 0) continue;
      set<string> s;
      int n = a / x;
      int m = b / y;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          vector<string> elem;
          for (int ii = i * x; ii < (i + 1) * x; ++ii) {
            elem.push_back(string());
            for (int jj = j * y; jj < (j + 1) * y; ++jj)
              elem.back() += arr[ii][jj];
          }
          if (0) {
            for (int ii = 0; ii < elem.size(); ++ii) cout << elem[ii] << endl;
            cout << endl;
          }
          vector<string> tmp = elem;
          string best = "";
          for (int k = 0; k < 4; ++k) {
            string str = rotate(tmp);
            if (x != y && k % 2 == 1)
              ;
            else if (best == "" || best > str)
              best = str;
          }
          s.insert(best);
        }
      }
      if (s.size() == n * m) {
        cnt++;
        answ.push_back(make_pair(x * y, make_pair(x, y)));
      }
    }
  }
  sort(answ.begin(), answ.end());
  cout << cnt << endl;
  cout << answ[0].second.first << " " << answ[0].second.second << endl;
  return 0;
}
