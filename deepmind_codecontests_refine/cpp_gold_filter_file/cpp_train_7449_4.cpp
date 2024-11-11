#include <bits/stdc++.h>
const char en = '\n';
using namespace std;
template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& par) {
  out << par.first << " " << par.second << en;
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (long long i = 0; i < (long long)(v.size()); i++) {
    if (i) out << " ";
    cout << v[i];
  }
  return out;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k, x;
  cin >> n >> k >> x;
  vector<long long> V(n, 0);
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      Q;
  int zaporne = 0;
  for (long long i = 0; i < (long long)(n); i++) {
    cin >> V[i];
    Q.push(make_pair(abs(V[i]), i));
    if (V[i] < 0) zaporne++;
  }
  while (Q.top().first == 0 && k > 0) {
    int pos = Q.top().second;
    Q.pop();
    if (zaporne % 2 == 0) {
      V[pos] -= x;
      Q.push(make_pair(x, pos));
      zaporne++;
    } else {
      Q.push(make_pair(x, pos));
      V[pos] += x;
    }
    k--;
  }
  if (zaporne % 2 == 0) {
    pair<long long, long long> t = Q.top();
    Q.pop();
    int pos = t.second;
    while (t.first >= 0 && k > 0) {
      t.first -= x;
      k--;
    }
    int minus = 1;
    minus *= (V[pos] < 0 ? -1 : 1);
    V[pos] = minus * t.first;
    Q.push(make_pair(abs(t.first), pos));
  }
  while (k--) {
    pair<long long, long long> t = Q.top();
    Q.pop();
    t.first += x;
    V[t.second] += (V[t.second] < 0 ? -1 : 1) * x;
    Q.push(t);
  }
  cout << V << endl;
}
