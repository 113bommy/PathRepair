#include <bits/stdc++.h>
using namespace std;
int m = 1000003;
bool compare1(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second > b.second;
}
bool compare2(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first > b.first;
}
double p = 3.14159265358979323846;
double area(int r) { return p * r * r; }
int abs(int a, int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
void assign(int a, int b, int c, map<int, int> &v) {
  if (v[a] == 1) {
    v[b] = 2;
    v[c] = 3;
  } else if (v[a] == 2) {
    v[b] = 1;
    v[c] = 3;
  } else {
    v[b] = 1;
    v[c] = 2;
  }
}
int main() {
  int n, d, i, s = 0;
  cin >> d >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
    s = s + (d - v[i]);
  }
  cout << s;
}
