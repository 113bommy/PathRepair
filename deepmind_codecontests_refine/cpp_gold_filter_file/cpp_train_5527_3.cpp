#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
void print(T1 a[], T2 n) {
  for (T2 i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
template <class T1, class T2>
void print(vector<T1> a, T2 n) {
  for (T2 i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
long long int modexpo(long long int a, long long int b, long long int m) {
  if (b == 0) {
    return 1;
  } else if (a == 1) {
    return 1;
  }
  if (b % 2 == 0) {
    long long int t = modexpo(a, b / 2, m);
    t = (t * t) % m;
    return t;
  } else {
    long long int t = modexpo(a, b / 2, m);
    t = (t * t) % m;
    t = (t * a) % m;
    return t;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  vector<long long int> a;
  a.push_back(0);
  for (int i = 0; i < n; i++) {
    long long int k;
    cin >> k;
    a.push_back(k);
  }
  a.push_back(m);
  vector<long long int> o;
  vector<long long int> e;
  o.push_back(0);
  e.push_back(0);
  for (int i = 1; i < a.size(); i++) {
    if (i & 1) {
      o.push_back(a[i] - a[i - 1]);
      e.push_back(0);
    } else {
      e.push_back(a[i] - a[i - 1]);
      o.push_back(0);
    }
  }
  for (int i = 1; i < o.size(); i++) {
    o[i] = o[i - 1] + o[i];
  }
  for (int i = 1; i < e.size(); i++) {
    e[i] = e[i - 1] + e[i];
  }
  long long int ans = o[o.size() - 1];
  for (int i = 0; i < o.size() - 1; i++) {
    long long int t1 = o[i];
    long long int t2 = e[o.size() - 1] - e[i + 1];
    long long int t = t1 + t2;
    long long int op1 = 0;
    if (i % 2 == 0) {
      if (a[i + 1] - a[i] > 1) {
        op1 = a[i + 1] - 1 - a[i];
      }
    } else {
      if (a[i + 1] - a[i] > 1) {
        op1 = 1;
      }
    }
    t += op1;
    ans = max(ans, t);
  }
  cout << ans << endl;
}
