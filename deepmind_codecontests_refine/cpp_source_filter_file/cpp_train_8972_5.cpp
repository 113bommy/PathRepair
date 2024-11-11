#include <bits/stdc++.h>
using namespace std;
long long vect(long long a, long long b, long long c) {
  cout << "2 " << a << ' ' << b << ' ' << c << endl;
  fflush(stdout);
  long long x;
  cin >> x;
  return x;
}
long long area(long long a, long long b, long long c) {
  cout << "1 " << a << ' ' << b << ' ' << c << endl;
  fflush(stdout);
  long long x;
  cin >> x;
  return x;
}
long long n;
vector<long long> lft, rght;
void div() {
  for (long long i = 3; i <= n; ++i) {
    if (vect(1, 2, i) == 1)
      lft.push_back(i);
    else
      rght.push_back(i);
  }
}
vector<long long> arr;
bool cmp(const long long& a, const long long& b) { return arr[a] < arr[b]; }
void solve(vector<long long>& a) {
  if (a.size() <= 1) return;
  long long v0 = 0;
  for (auto elem : a) {
    arr[elem] = area(1, 2, elem);
    if (arr[elem] > arr[v0]) {
      v0 = elem;
    }
  }
  vector<long long> l, r;
  for (auto v : a) {
    if (v == v0) continue;
    if (vect(1, v0, v) == 1) {
      l.push_back(v);
    } else {
      r.push_back(v);
    }
  }
  sort(l.begin(), l.end(), cmp);
  sort(r.begin(), r.end(), cmp);
  reverse(r.begin(), r.end());
  a.clear();
  for (auto elem : r) {
    a.push_back(elem);
  }
  a.push_back(v0);
  for (auto elem : l) {
    a.push_back(elem);
  }
}
int32_t main() {
  cin >> n;
  arr.resize(n + 1);
  div();
  solve(lft);
  solve(rght);
  cout << "0 1 ";
  for (auto elem : rght) cout << elem << ' ';
  cout << "2 ";
  for (auto elem : lft) cout << elem << ' ';
  fflush(stdout);
}
