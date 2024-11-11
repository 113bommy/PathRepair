#include <bits/stdc++.h>
using namespace std;
long long int ceil2(long long int a, long long int b) {
  long long int c = a / b;
  if (a % b != 0) c++;
  return c;
}
void _print(long long int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
const long long int N = 105;
char arr[4][N];
long long int ans = 0;
long long int n;
void runtestCase() {
  for (long long int i = 1; i <= 2; i++) {
    string s;
    cin >> s;
    n = s.size();
    for (long long int j = 1; j <= n; j++) {
      arr[i][j] = s[j - 1];
    }
  }
  for (long long int j = 1; j <= n - 1; j++) {
    if (arr[1][j] == '0' && arr[2][j] == '0') {
      if (arr[1][j + 1] == '0') {
        ans += 1;
        arr[1][j] = '1';
        arr[2][j] = '1';
        arr[1][j + 1] = '1';
      } else if (arr[2][j + 1] == '0') {
        ans += 1;
        arr[1][j] = '1';
        arr[2][j] = '1';
        arr[2][j + 1] = '1';
      }
    } else if (arr[1][j] == '0' || arr[2][j] == '0') {
      if (arr[1][j + 1] == '0' && arr[2][j + 1] == '0') {
        ans += 1;
        arr[1][j + 1] = '1';
        arr[2][j + 1] = '1';
      }
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    runtestCase();
  }
  return 0;
}
