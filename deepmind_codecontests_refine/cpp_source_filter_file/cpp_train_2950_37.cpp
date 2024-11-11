#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, k, h;
int mass[MAXN];
int speed[MAXN];
vector<int> ind;
bool my_comp(const int& i, const int& j) {
  if (mass[i] < mass[j]) return true;
  if (mass[i] > mass[j]) return false;
  if (speed[i] < speed[j]) return true;
  return false;
}
bool tryout(long double t) {
  int next = k;
  for (int i = n - 1; i >= 0; --i) {
    if (next <= 0) break;
    long double tmp = (long double)(next * h) / speed[ind[i]];
    if (tmp < t + 1e-18) {
      --next;
    }
  }
  if (next <= 0) {
    return true;
  }
  return false;
}
void print(long double t) {
  int next = k;
  vector<int> ret(k);
  for (int i = n - 1; i >= 0; --i) {
    if (next <= 0) break;
    long double tmp = (long double)(next * h) / speed[ind[i]];
    if (tmp < t + 1e-18) {
      --next;
      ret[next] = ind[i] + 1;
    }
  }
  for (int i = 0; i < k; ++i) {
    cout << ret[i];
    if (i < k - 1) cout << " ";
  }
  cout << endl;
}
int main() {
  cin >> n >> k >> h;
  for (int i = 0; i < n; ++i) {
    cin >> mass[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> speed[i];
  }
  ind.resize(n);
  for (int i = 0; i < n; ++i) {
    ind[i] = i;
  }
  sort(ind.begin(), ind.end(), my_comp);
  long double L = 0.0;
  long double R = 1e9;
  for (int iters = 0; iters < 90; ++iters) {
    long double Q = (L + R) / 2.0;
    bool ok = tryout(Q);
    if (ok) {
      R = Q;
    } else {
      L = Q;
    }
  }
  print(R);
  return 0;
}
