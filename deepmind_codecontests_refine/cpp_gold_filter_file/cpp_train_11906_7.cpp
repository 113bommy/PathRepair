#include <bits/stdc++.h>
using namespace std;
template <class t>
ostream &operator<<(ostream &tout, const vector<t> &s) {
  tout << '[';
  for (int i = 0; i < s.size(); i++)
    if (i + 1 == s.size())
      tout << s[i];
    else
      tout << s[i] << ',';
  tout << ']';
  return (tout);
}
template <class a, class b>
ostream &operator<<(ostream &tout, const pair<a, b> &c) {
  return (tout << '(' << c.first << ',' << c.second << ')');
}
template <class T>
struct __set__print {
  __set__print(ostream &out) : tout(out), count(0) {}
  void operator()(T x) {
    if (count > 0) tout << ',';
    tout << x;
    ++count;
  }
  ostream &tout;
  int count;
};
template <class T>
ostream &operator<<(ostream &tout, const set<T> &s) {
  tout << '{';
  for_each(s.begin(), s.end(), __set__print<T>(tout));
  return (tout << '}');
}
template <class T, class Q>
struct print_map {
  print_map(ostream &out) : tout(out), count(0) {}
  void operator()(const pair<T, Q> &x) {
    if (count > 0) tout << ',';
    tout << '(' << x.first << " => " << x.second << ')';
    ++count;
  }
  ostream &tout;
  int count;
};
template <class T, class Q>
ostream &operator<<(ostream &tout, map<T, Q> s) {
  tout << '{';
  for_each(s.begin(), s.end(), print_map<T, Q>(tout));
  return (tout << '}');
}
template <class T>
string to_string(T s) {
  stringstream tin;
  tin << s;
  string res;
  getline(tin, res);
  return (res);
}
template <class T>
vector<T> to_vector(T *s, int n) {
  vector<T> result;
  for (int i = 0; i < n; i++) result.push_back(s[i]);
  return (result);
}
const int MAX_N = 600000 + 20;
bool answer[MAX_N];
int n, m, _x_fucking_1[MAX_N], _y_fucking_1[MAX_N], _x_fucknig_2[MAX_N],
    _y_fucking_2[MAX_N];
long long up[501][501][10], down[501][501][10];
long long t[501][501][10];
void tr_up(int x, int y, int index) {
  up[x][y][index / 60] |= 1ll << (index % 60);
}
void tr_down(int x, int y, int index) {
  down[x][y][index / 60] |= 1ll << (index % 60);
}
char num[501][501];
void cal(int b_1, int b_2, const vector<int> &inds) {
  if (b_1 == b_2) {
    for (int i = 1; i <= m; i++) {
      int temp = i;
      while (num[b_1][temp] == '.') {
        tr_down(b_1, i, temp);
        tr_up(b_1, temp, i);
        temp++;
      }
    }
    for (int i = 0; i < inds.size(); i++)
      if (down[b_1][_y_fucking_1[inds[i]]][_y_fucking_2[inds[i]] / 60] &
          (1ll << (_y_fucking_2[inds[i]] % 60)))
        answer[inds[i]] = true;
    return;
  }
  int mid = (b_1 + b_2) / 2;
  vector<int> a, b, c;
  for (int i = 0; i < inds.size(); i++)
    if (_x_fucking_1[inds[i]] <= mid && _x_fucknig_2[inds[i]] <= mid)
      a.push_back(inds[i]);
    else if (_x_fucking_1[inds[i]] > mid && _x_fucknig_2[inds[i]] > mid)
      b.push_back(inds[i]);
    else if (_x_fucking_1[inds[i]] <= _x_fucknig_2[inds[i]])
      c.push_back(inds[i]);
  cal(b_1, mid, a);
  cal(mid + 1, b_2, b);
  for (int i = 0; i < c.size(); i++)
    for (int j = 0; j < 10; j++)
      if (down[_x_fucking_1[c[i]]][_y_fucking_1[c[i]]][j] &
          up[_x_fucknig_2[c[i]]][_y_fucking_2[c[i]]][j])
        answer[c[i]] = true;
  for (int i = mid; i >= b_1; i--)
    for (int j = m; j >= 1; j--) {
      for (int a = 0; a < 10; a++) down[i][j][a] = 0;
      if (num[i][j] == '.') {
        if (num[i][j + 1] == '.')
          for (int a = 0; a < 10; a++) down[i][j][a] |= down[i][j + 1][a];
        if (num[i + 1][j] == '.')
          for (int a = 0; a < 10; a++) down[i][j][a] |= down[i + 1][j][a];
      }
    }
  for (int i = mid + 1; i <= b_2; i++)
    for (int j = 1; j <= m; j++) {
      for (int a = 0; a < 10; a++) up[i][j][a] = 0;
      if (num[i][j] == '.') {
        if (num[i - 1][j] == '.')
          for (int a = 0; a < 10; a++) up[i][j][a] |= up[i - 1][j][a];
        if (num[i][j - 1] == '.')
          for (int a = 0; a < 10; a++) up[i][j][a] |= up[i][j - 1][a];
      }
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> num[i][j];
  int amount;
  cin >> amount;
  vector<int> all;
  for (int i = 1; i <= amount; i++) {
    cin >> _x_fucking_1[i] >> _y_fucking_1[i] >> _x_fucknig_2[i] >>
        _y_fucking_2[i];
    all.push_back(i);
  }
  cal(1, n, all);
  for (int i = 1; i <= amount; i++)
    if (answer[i])
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
}
