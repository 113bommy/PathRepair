#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <typename t>
t abs(t a) {
  if (a >= 0) return a;
  return -a;
}
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << "  ";
  err(++it, args...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  vector<int> vx, vy, xt, yt;
  cin >> n;
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    int tmp;
    cin >> tmp;
    vx.push_back(tmp);
  }
  int y;
  cin >> y;
  for (int i = 0; i < y; i++) {
    int tmp;
    cin >> tmp;
    vy.push_back(tmp);
  }
  xt = vx;
  yt = vy;
  int ct = 0;
  while (1) {
    ct++;
    if (xt[0] > yt[0]) {
      xt.push_back(yt[0]);
      xt.push_back(xt[0]);
    } else {
      yt.push_back(xt[0]);
      yt.push_back(yt[0]);
    }
    xt.erase(xt.begin());
    yt.erase(yt.begin());
    if ((xt == vx && yt == vy) || ct > 100000) {
      cout << "-1" << endl;
      return 0;
    }
    if (xt.empty()) {
      cout << ct << " 2" << endl;
      return 0;
    } else if (yt.empty()) {
      cout << ct << " 1" << endl;
      return 0;
    }
  }
  return 0;
}
