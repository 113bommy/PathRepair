#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long int mod1 = 1e9 + 7;
long long int INF = 1e9 + 5;
long long int mod = 998244353;
void solve(long long int test_case) {
  string s;
  cin >> s;
  long long int n = s.size();
  long long int take = n / 2;
  string ans, rev;
  long long int i = 0, j = n - 1;
  while (j >= i && take) {
    if (j > i && s[i] == s[j]) {
      ans.push_back(s[i]);
      rev.push_back(s[i]);
      i++;
      j--;
      take -= 2;
    } else if (j - 1 > i && s[i] == s[j - 1]) {
      ans.push_back(s[i]);
      rev.push_back(s[i]);
      j -= 2;
      i++;
      take -= 2;
    } else if (j > i + 1 && s[i + 1] == s[j]) {
      ans.push_back(s[j]);
      rev.push_back(s[j]);
      j--;
      i += 2;
      take -= 2;
    } else if (j - 1 > i + 1 && s[j - 1] == s[i + 1]) {
      ans.push_back(s[j - 1]);
      rev.push_back(s[j - 1]);
      j -= 2;
      i += 2;
      take -= 2;
    } else {
      ans.push_back(s[i]);
      i++;
      take--;
      break;
    }
  }
  reverse(rev.begin(), rev.end());
  ans += rev;
  if (take || ans.size() < n / 2) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << ans;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  long long int i = 1ll;
  while (t--) {
    solve(i);
    i++;
  }
}
