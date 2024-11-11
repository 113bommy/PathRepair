#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const int LIM = 2e5 + 5, MOD = 1e9 + 7;
const long double EPS = 1e-9;
int read() {
  int xx = 0, ff = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = (xx << 3) + (xx << 1) + ch - '0';
    ch = getchar();
  }
  return xx * ff;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long l[n];
  vector<long long> v;
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  string temp;
  cin >> temp;
  string str;
  char c = 'l';
  int curr = -1;
  long long tot = 0;
  for (int i = 0; i < temp.length(); ++i) {
    if (temp[i] == c) {
      tot += l[i];
    } else {
      if (c != 'l') {
        str += c;
        v.push_back(tot);
      }
      c = temp[i];
      curr = i;
      tot = l[i];
    }
  }
  str += c;
  v.push_back(tot);
  for (int i = 0; i < v.size(); ++i) v[i] *= 2;
  n = str.length();
  bool w = 0;
  long long t = 0;
  long long s = 0;
  long long g = 0;
  long long wa = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'G') {
      t += 5 * v[i];
      s += v[i];
      g += v[i];
    }
    if (str[i] == 'W') {
      t += 3 * v[i];
      s += v[i];
      w = 1;
      w += v[i];
      wa += v[i];
    }
    if (str[i] == 'L') {
      if (s < v[i]) {
        if (w) {
          t += 3 * (v[i] - s);
          wa = 0;
        } else {
          t += 5 * (v[i] - s);
          g = 0;
        }
        s = v[i];
      }
      s -= v[i];
      t += v[i];
    }
    if (s < 2 * (g + w)) {
      long long red = min(s / 2, g);
      g = red;
      w = min(wa, (s / 2) - red);
    }
  }
  long long red = min(g, s / 2);
  t -= 4 * red;
  s -= red * 2;
  long long red2 = min(wa, s / 2);
  t -= 2 * red2;
  s -= red2 * 2;
  cout << t / 2 << '\n';
  return 0;
}
