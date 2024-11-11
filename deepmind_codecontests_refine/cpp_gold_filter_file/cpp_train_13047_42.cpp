#include <bits/stdc++.h>
using namespace std;
struct lem {
  long long m;
  long long v;
  int id;
  bool operator<(const lem& other) const {
    if (m > other.m) return true;
    if (m < other.m) return false;
    if (v > other.v) return true;
    if (v < other.v) return false;
    return id > other.id;
  }
};
int N, K, H;
lem L[100010];
int asst[100010];
int tempa[100010];
bool solve(long double t) {
  memset(tempa, 0, sizeof(tempa));
  int start = 0;
  for (int k = K; k >= 1; k--) {
    bool found = false;
    for (int i = (start); i <= (N - 1); i++) {
      long double time =
          ((long double)k) / ((long double)L[i].v) * ((long double)H);
      if (time <= t) {
        found = true;
        tempa[k] = i;
        start = i + 1;
        break;
      }
    }
    if (!found) return false;
  }
  return true;
}
int main() {
  cin >> N >> K >> H;
  for (int i = 0; i < N; i++) cin >> L[i].m;
  for (int i = 0; i < N; i++) cin >> L[i].v;
  for (int i = 0; i < N; i++) L[i].id = i + 1;
  sort(L, L + N);
  long double low = 0.l;
  long double high = 1000000000.l;
  int times = 100;
  while (times--) {
    long double t = (low + high) / 2.l;
    if (solve(t)) {
      for (int i = (1); i <= (K); i++) asst[i] = tempa[i];
      high = t;
    } else {
      low = t;
    }
  }
  for (int k = (1); k <= (K); k++) {
    if (k > 1) cout << " ";
    cout << L[asst[k]].id;
  }
  cout << endl;
}
