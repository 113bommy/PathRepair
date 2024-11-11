#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
int main() {
  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;
  int a, b;
  char c;
  vector<pair<pair<int, int>, char> > data;
  for (int i = 0; i < n; i++) {
    cin >> c;
    cin >> a >> b;
    a -= x;
    b -= y;
    if (abs(a) == abs(b) || a == 0 || b == 0) {
      data.push_back(make_pair((make_pair((a), (b))), (c)));
    }
  }
  bool flag = false;
  int mi;
  char check;
  mi = 1000000005;
  check = 'X';
  for (int i = 0; i < data.size(); i++) {
    a = data[i].first.first;
    b = data[i].first.second;
    c = data[i].second;
    if (a == b && a > 0) {
      if (mi > a) {
        mi = a;
        check = c;
      }
    }
  }
  if (check == 'B' || check == 'Q') flag = true;
  mi = 1000000005;
  check = 'X';
  for (int i = 0; i < data.size(); i++) {
    a = data[i].first.first;
    b = data[i].first.second;
    c = data[i].second;
    if (a == -b && a > 0) {
      if (mi > a) {
        mi = a;
        check = c;
      }
    }
  }
  if (check == 'B' || check == 'Q') flag = true;
  mi = 1000000005;
  check = 'X';
  for (int i = 0; i < data.size(); i++) {
    a = data[i].first.first;
    b = data[i].first.second;
    c = data[i].second;
    if (b == -a && b > 0) {
      if (mi > b) {
        mi = b;
        check = c;
      }
    }
  }
  if (check == 'B' || check == 'Q') flag = true;
  mi = 1000000005;
  check = 'X';
  for (int i = 0; i < data.size(); i++) {
    a = data[i].first.first;
    b = data[i].first.second;
    c = data[i].second;
    if (b == a && a < 0) {
      if (mi > -b) {
        mi = -b;
        check = c;
      }
    }
  }
  if (check == 'B' || check == 'Q') flag = true;
  mi = 1000000005;
  check = 'X';
  for (int i = 0; i < data.size(); i++) {
    a = data[i].first.first;
    b = data[i].first.second;
    c = data[i].second;
    if (a == 0 && b > 0) {
      if (mi > b) {
        mi = b;
        check = c;
      }
    }
  }
  if (check == 'R' || check == 'Q') flag = true;
  mi = 1000000005;
  check = 'X';
  for (int i = 0; i < data.size(); i++) {
    a = data[i].first.first;
    b = data[i].first.second;
    c = data[i].second;
    if (a == 0 && b < 0) {
      if (mi > -b) {
        mi = -b;
        check = c;
      }
    }
  }
  if (check == 'R' || check == 'Q') flag = true;
  mi = 1000000005;
  check = 'X';
  for (int i = 0; i < data.size(); i++) {
    a = data[i].first.first;
    b = data[i].first.second;
    c = data[i].second;
    if (b == 0 && a > 0) {
      if (mi > a) {
        mi = a;
        check = c;
      }
    }
  }
  if (check == 'R' || check == 'Q') flag = true;
  mi = 1000000005;
  check = 'X';
  for (int i = 0; i < data.size(); i++) {
    a = data[i].first.first;
    b = data[i].first.second;
    c = data[i].second;
    if (b == 0 && a < 0) {
      if (mi > -a) {
        mi = -a;
        check = c;
      }
    }
  }
  if (check == 'R' || check == 'Q') flag = true;
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
