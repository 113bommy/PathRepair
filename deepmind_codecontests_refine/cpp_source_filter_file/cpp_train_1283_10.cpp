#include <bits/stdc++.h>
using namespace std;
int R = 1e9 + 7;
template <typename T>
T last(vector<T>& v) {
  return v[v.size() - 1];
}
template <typename T>
void print(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << endl;
}
template <typename T1, typename T2>
void print(vector<pair<T1, T2>>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    cout << '(' << v[i].first << ',' << v[i].second << "),";
  }
  cout << "]" << endl;
}
template <typename T>
void print(vector<vector<T>>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    print(v[i]);
  }
  cout << "]" << endl;
}
template <typename T>
void print(set<T>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i << ' ';
  }
  cout << "}" << endl;
}
template <typename T1, typename T2>
void print(map<T1, T2>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i.first << ':' << i.second << ',';
  }
  cout << "}" << endl;
}
template <typename T>
bool in(set<T>& indices, T x) {
  return indices.find(x) != indices.end();
}
template <typename T, typename T_>
bool in(map<T, T_>& indices, T x) {
  return indices.find(x) != indices.end();
}
int power(int x, int y) {
  int res = 1;
  x = x % R;
  if (x == 0) return 0;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x) % R;
    y /= 2;
    x = (x * x) % R;
  }
  return res;
}
bool compare(int a, int b) { return (a < b); }
void TestCase() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(n);
  vector<pair<char, int>> said(n);
  for (int i = 0; i < n; i++) {
    char sign;
    cin >> sign;
    int x;
    cin >> x;
    x--;
    if (sign == '+') {
      a[x]++;
    } else
      b[x]++;
    said[i] = make_pair(sign, x);
  }
  int sum = 0;
  for (int i = 0; i < n; i++) sum += b[i];
  set<int> suspects;
  for (int i = 0; i < n; i++) {
    int truth = a[i] + sum - b[i];
    if (truth == m) suspects.insert(i);
  }
  for (auto i : said) {
    char sign = i.first;
    int x = i.second;
    if (sign == '+') {
      if (in(suspects, x)) {
        if ((int)suspects.size() == 1) {
          cout << "Truth" << '\n';
        } else {
          cout << "Not Defined" << '\n';
        }
      } else {
        cout << "Lie" << '\n';
      }
    } else {
      if (in(suspects, x)) {
        if ((int)suspects.size() == 1) {
          cout << "Lie" << '\n';
        } else {
          cout << "Not Defined" << '\n';
        }
      } else {
        cout << "Truth" << '\n';
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  T = 1;
  for (int tt = 1; tt <= T; tt++) {
    TestCase();
  }
}
