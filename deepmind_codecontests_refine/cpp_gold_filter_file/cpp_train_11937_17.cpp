#include <bits/stdc++.h>
using namespace std;
int check_white(vector<vector<int> > &p1, int n) {
  int ans = 0;
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (p1[i][j] != k) ans++;
      k = (k + 1) % 2;
    }
  }
  return ans;
}
int check_black(vector<vector<int> > &p1, int n) {
  int ans = 0;
  int k = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (p1[i][j] != k) ans++;
      k = (k + 1) % 2;
    }
  }
  return ans;
}
void scan(vector<vector<int> > &p1, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      string s;
      cin >> c;
      s += c;
      p1[i][j] = stoi(s);
    }
  }
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > p1(n, vector<int>(n));
  vector<vector<int> > p2(n, vector<int>(n));
  vector<vector<int> > p3(n, vector<int>(n));
  vector<vector<int> > p4(n, vector<int>(n));
  scan(p1, n);
  scan(p2, n);
  scan(p3, n);
  scan(p4, n);
  vector<pair<int, int> > dos(5);
  dos[1].first = check_white(p1, n);
  dos[1].second = check_black(p1, n);
  dos[2].first = check_white(p2, n);
  dos[2].second = check_black(p2, n);
  dos[3].first = check_white(p3, n);
  dos[3].second = check_black(p3, n);
  dos[4].first = check_white(p4, n);
  dos[4].second = check_black(p4, n);
  int b2 = min(dos[3].first + dos[4].second, dos[4].first + dos[3].second);
  int b1 = dos[3].first + dos[4].first;
  int b3 = dos[3].second + dos[4].second;
  int b4 = dos[1].second + min(b1 + dos[2].second, b2 + dos[2].first);
  int b5 = dos[1].first + min(b3 + dos[2].first, b2 + dos[2].second);
  cout << min(b4, b5);
}
