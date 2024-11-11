#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a;
  cout << '\n';
  err(++it, args...);
}
void read(vector<long long> &v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
}
long long n, m, a, b, c, k, temp, x, y;
void solveforthiscase(const int &test) {
  cin >> n >> m;
  vector<long long> v(n);
  read(v);
  vector<long long> temp(n);
  for (int i = 0; i < n; i++) {
    temp[i] = v[i];
  }
  sort(temp.begin(), temp.end());
  vector<long long> p(m);
  read(p);
  sort(p.begin(), p.end());
  int val = 1;
  for (int i = 0; i < m; i++) {
    val = p[i];
    int j = i + 1;
    while (j < m && p[j] == val + 1) {
      val++;
      j++;
    }
    j--;
    sort(v.begin() + p[i] - 1, v.begin() + min(p[j] + 1, n));
    i = j;
  }
  for (int i = 0; i < n; i++) {
    if (temp[i] != v[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  cin >> test;
  for (int i = 1; i <= test; i++) {
    solveforthiscase(i);
  }
}
