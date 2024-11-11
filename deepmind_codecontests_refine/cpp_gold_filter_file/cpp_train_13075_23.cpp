#include <bits/stdc++.h>
using namespace std;
bool cl(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}
bool clg(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first > b.first;
}
bool cr(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
int dist(pair<int, int> a, pair<int, int> b) {
  if (b.second >= a.first && b.second <= a.second) return 0;
  if (b.first >= a.first && b.first <= a.second) return 0;
  if (b.second <= a.first) return a.first - b.second;
  if (a.second <= b.first) return b.first - a.second;
}
int gcd(int a, int b) {
  int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
vector<int> difference(string s, string t, int shift, int *val) {
  vector<int> dpos;
  *val = 0;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] != t[shift + i]) {
      dpos.push_back(i + 1);
      (*val)++;
    }
  return dpos;
}
void task(void) {
  int m, n;
  string s, t;
  scanf("%i", &(n));
  ;
  scanf("%i", &(m));
  ;
  cin >> s;
  cin >> t;
  int min = 1e9;
  vector<int> min_pos;
  for (int shift = 0; shift <= m - n; ++shift) {
    int val;
    vector<int> pos;
    pos = difference(s, t, shift, &val);
    if (val < min) {
      min = val;
      min_pos = pos;
    }
  }
  printf("%i\n", min);
  for (int i = 0; i < min_pos.size(); ++i) printf("%i ", min_pos[i]);
}
int main(void) { task(); }
