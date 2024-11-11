#include <bits/stdc++.h>
using namespace std;
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char* s) { return to_string((string)s); }
string to_string(const char c) {
  string s = "'";
  s += c;
  s += "'";
  return s;
}
template <class T, class U>
string to_string(const pair<T, U>& p) {
  string s = "(";
  s += to_string(p.first);
  s += ", ";
  s += to_string(p.second);
  s += ")";
  return s;
}
template <class T>
string to_string(const T& a) {
  bool first = true;
  string s = "{";
  for (const auto& x : a) {
    if (!first) {
      s += ", ";
    }
    first = false;
    s += to_string(x);
  }
  s += "}";
  return s;
}
void debug_out() { cerr << '\n'; }
template <class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
  cerr << ' ' << to_string(head);
  debug_out(tail...);
}
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int inf = 1e9 + 100;
const ll inf64 = 7e18l;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  vector<int> used(n);
  vector<int> a(n + 1, -1);
  cout << "? ";
  for (int i = 1; i <= k; ++i) {
    cout << i << ' ';
  }
  cout << endl;
  int pos, res;
  cin >> pos >> res;
  a[pos] = res;
  vector<int> query;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == -1) {
      query.push_back(i);
      if ((int)query.size() == k) {
        break;
      }
    }
  }
  cout << "? ";
  for (int x : query) {
    cout << x << ' ';
  }
  cout << endl;
  int pos2, res2;
  cin >> pos2 >> res2;
  a[pos2] = res;
  int ok = res2 > res;
  int cnt = 0;
  for (int i = 0; i < k; ++i) {
    if (query[i] == pos2) {
      continue;
    }
    vector<int> query2 = query;
    query2[i] = pos;
    cout << "? ";
    for (int x : query2) {
      cout << x << ' ';
    }
    cout << endl;
    int res3, pos3;
    cin >> pos3 >> res3;
    if (pos3 != pos2) {
      ++cnt;
    }
  }
  if (ok) {
    cnt = k - 1 - cnt;
  }
  cout << cnt + 1 << endl;
  return 0;
}
