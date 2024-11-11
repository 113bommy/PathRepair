#include <bits/stdc++.h>
using namespace std;
const int MAX_N = int(1e5 + 3);
template <typename T>
void printV(vector<T> v, char sep) {
  for (long long unsigned int i = 0; i < v.size() - 1; i++) {
    cout << v[i] << sep;
  }
  cout << v[v.size() - 1];
}
void printVPCI(vector<pair<char, int>> s) {
  for (long long unsigned int i = 0; i < s.size(); i++) {
    cout << s[i].first << " " << s[i].second << "\n";
  }
}
void cdPr(bool a) { cout << (a ? "YES" : "NO"); }
bool isPrime(int n) {
  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
template <typename T>
bool vFind(vector<T> v, T x) {
  return find(v.begin(), v.end(), x) != v.end();
}
vector<pair<char, int>> strInfo(string s) {
  vector<char> f;
  vector<pair<char, int>> r;
  for (long long unsigned int i = 0; i < s.size(); i++) {
    if (!vFind(f, s[i])) {
      f.push_back(s[i]);
      r.push_back(make_pair(s[i], count(s.begin(), s.end(), s[i])));
    }
  }
  return r;
}
vector<char> distinctChars(string s) {
  vector<char> f;
  for (long long unsigned int i = 0; i < s.size(); i++) {
    if (!vFind(f, s[i])) f.push_back(s[i]);
  }
  return f;
}
void solve() {
  int n;
  cin >> n;
  int pos[MAX_N] = {0};
  int t = n;
  int a;
  cin >> a;
  int i = 1;
  n--;
  int min = 99999999;
  int r = 0;
  pos[0] = a;
  int x;
  while (n > 0) {
    cin >> x;
    pos[i] = x;
    if (abs(a - x) < min) {
      min = abs(a - x);
      r = i;
    }
    a = x;
    i++;
    n--;
  }
  if (abs(x - pos[0]) < min) {
    r = t;
  }
  cout << (r) << " " << ((r + 1 >= t) ? (r + 1 - t) : (r + 1)) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
