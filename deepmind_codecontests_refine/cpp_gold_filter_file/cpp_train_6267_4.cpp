#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const long long mod = (int)1e9 + 7;
vector<int> divisor(int n) {
  vector<int> ret;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort((ret).begin(), (ret).end());
  return (ret);
}
int main() {
  int n;
  vector<int> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x) v.push_back(i);
  }
  int num = ((long long)(v).size());
  vector<int> matr(num - 1);
  int sum = 0;
  if (num == 1) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < num - 1; i++) {
    matr[i] = v[i + 1] - v[i];
    sum += matr[i];
  }
  vector<int> div = divisor(num);
  div.push_back(num);
  long long mini = INF;
  for (auto x : div) {
    long long ssum = 0;
    for (int i = 0; i < num; i++) {
      if (i % x < x / 2)
        ssum -= v[i];
      else if (i % x == x / 2)
        ssum -= v[i] * (x % 2 - 1);
      else
        ssum += v[i];
    }
    chmin(mini, ssum);
  }
  cout << mini;
}
