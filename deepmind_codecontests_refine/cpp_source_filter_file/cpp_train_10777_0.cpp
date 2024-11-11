#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 1000001000;
const int mod = 1000 * 1000 * 1000 + 7;
const int mod9 = 1000 * 1000 * 1000 + 9;
const double PI = 3.1415926535897932;
double sqr(double first) { return first * first; };
long double sqr(long double first) { return first * first; };
long long sqr(long long first) { return first * first; };
long long sqr(int first) { return first * 1LL * first; };
long long gcd(long long a, long long b) {
  while (b) a %= b, swap(a, b);
  return a;
}
long long bpm(long long a, long long n = -2, long long m = mod) {
  n = n >= 0 ? n : m + n;
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % m;
    a = (a * a) % m;
    n >>= 1;
  }
  return r;
}
long long dist(long long x1, long long y1, long long x2, long long y2) {
  return sqr(x1 - x2) + sqr(y1 - y2);
}
std::ostream& operator<<(std::ostream& os, pair<int, int> p) {
  return os << "{" << p.first << " " << p.second << "}";
}
const int N = 200005;
string s = "http://";
bool split(string d, string& name, string& path) {
  if (d.length() > 60) return false;
  name = path = "";
  int i = s.length();
  for (; i < d.length() && d[i] != '/'; i++) {
    if (d[i] == '.' && d[i - 1] == '.') {
      return false;
    }
    if (d[i] <= 'z' && d[i] >= 'a' || d[i] <= 'Z' && d[i] >= 'A' || d[i] == '.')
      name += d[i];
    else
      return false;
  }
  for (; i < d.length(); i++) {
    if (d[i] == '/' && d[i - 1] == '/') {
      return false;
    }
    if (d[i] <= 'z' && d[i] >= 'a' || d[i] <= 'Z' && d[i] >= 'A' ||
        d[i] == '/' || d[i] == '.')
      path += d[i];
    else
      return false;
  }
  if (!name.length() || name.length() > 20 || path.length() > 20) return false;
  return true;
}
int main() {
  map<string, set<string> > mp;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string d;
    cin >> d;
    string name, path;
    if (split(d, name, path)) {
      mp[name].insert(path);
    }
  }
  map<set<string>, vector<string> > ms;
  for (auto& it : mp) {
    ms[it.second].push_back(it.first);
  }
  vector<vector<string> > vs;
  for (auto it : ms) {
    if (it.second.size() > 1) {
      vs.push_back(it.second);
    }
  }
  cout << vs.size() << "\n";
  for (auto& d : vs) {
    for (auto& first : d) {
      cout << s << first << " ";
    }
    cout << "\n";
  }
  return 0;
}
