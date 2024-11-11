#include <bits/stdc++.h>
using namespace std;
int a, b;
int arr[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
map<char, int> mp;
string inp;
pair<int, int> go(int c, int d) {
  int ln = inp.size();
  for (int i = 0; i < ln; i++) {
    c += arr[mp[inp[i]]][0];
    d += arr[mp[inp[i]]][1];
    if (c == a && d == b) {
      puts("Yes");
      return make_pair(-2000000000, -2000000000);
    }
  }
  return make_pair(c, d);
}
int main() {
  mp['U'] = 0;
  mp['D'] = 1;
  mp['L'] = 2;
  mp['R'] = 3;
  cin >> a >> b;
  cin >> inp;
  if (a == 0 && b == 0) {
    puts("Yes");
    return 0;
  }
  pair<int, int> p1;
  p1 = go(0, 0);
  if (p1.first == -2000000000) return 0;
  if (p1.first == 0 && p1.second == 0) {
    cout << "No";
    return 0;
  }
  pair<int, int> p2;
  p2 = p1;
  if (abs(a) <= 500 && abs(b) <= 500) {
    for (int i = 1; i <= 2000; i++) {
      p2 = go(p2.first, p2.second);
      if (p2.first == -2000000000) return 0;
    }
    cout << "No";
    return 0;
  } else {
    for (int i = 1; i <= 2000; i++) {
      p2 = go(p2.first, p2.second);
      if (p2.first == -2000000000) return 0;
    }
    int e;
    if (p1.first == 0)
      e = b / p1.second;
    else
      e = a / p1.first;
    if (e < 0) {
      cout << "No";
      return 0;
    }
    e = max(0, e - 200);
    p1.first *= e;
    p1.second *= e;
    p2 = p1;
    for (int i = 1; i <= 2000; i++) {
      p2 = go(p2.first, p2.second);
      if (p2.first == -2000000000) return 0;
    }
    cout << "No";
  }
  return 0;
}
