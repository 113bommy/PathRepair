#include <bits/stdc++.h>
template <class T>
typename T::value_type arr_sum(const T& v, int n) {
  typename T::value_type sum = 0;
  for (int i = 0; i < n; ++i) sum += v[i];
  return sum;
}
using namespace std;
vector<long long> t(1000001);
int n;
vector<long long> s(1000001);
void init(int nn) {
  n = nn;
  t.assign(n, 0);
}
long long sum(int r) {
  long long result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];
  return result;
}
void inc(int i, int delta) {
  for (; i < n; i = (i | (i + 1))) t[i] += delta;
}
int sum(int l, int r) { return sum(r) - sum(l - 1); }
void init(vector<long long>& a) {
  init((int)a.size());
  for (unsigned i = 0; i < a.size(); i++) inc(i, a[i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  ;
  map<int, int> first;
  map<int, int> last;
  vector<int> f(n);
  vector<int> l(n);
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    f[i] = first[v[i]] + 1;
    first[v[i]]++;
    s[f[i]]++;
  }
  s[0] = 0;
  init(s);
  for (int i = n - 1; i >= 0; --i) {
    l[i] = last[v[i]] + 1;
    last[v[i]]++;
  }
  for (int i = 0; i <= n - 2; ++i) {
    inc(f[i], -1);
    res += sum(l[i] - 1);
  }
  cout << res;
  return 0;
}
