#include <bits/stdc++.h>
using namespace std;
bool d(string s, string c) {
  if (s.size() < c.size()) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] < c[i])
        return true;
      else if (s[i] > c[i])
        return false;
    }
    return true;
  } else {
    for (int i = 0; i < c.size(); i++) {
      if (s[i] < c[i])
        return true;
      else if (s[i] > c[i])
        return false;
    }
    return false;
  }
}
bool cmp(pair<string, int> i, pair<string, int> j) {
  if (i.second > j.second)
    return true;
  else if (j.second == i.second && j.first > i.first)
    return true;
  else
    return false;
}
void in_out_txt() {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
}
int fun(int &n) {
  int x, y = 1;
  if (n == 1) {
    n--;
    return 2;
  }
  for (int i = 1; i <= n; i++) {
    x = (i * (i + 1) / 2);
    if (x > n) {
      n -= y;
      return i;
    }
    y = x;
  }
}
int main() {
  int n, x, y, z;
  cin >> n;
  char c = 'a';
  vector<int> asd;
  while (n > 0) {
    x = fun(n);
    asd.push_back(x);
  }
  for (int i = 0; i < asd.size(); i++) {
    for (int j = 0; j < asd[i]; j++) cout << c;
    c++;
  }
  cout << c << endl;
  return 0;
}
