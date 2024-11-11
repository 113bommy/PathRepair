#include <bits/stdc++.h>
using namespace std;
const long long MAX = 3e5;
long long a[MAX];
struct Truck {
  long long s, f, c, r;
} T[MAX];
bool isPossible(long long pos, long long V) {
  long long tank = V;
  long long r = T[pos].r;
  for (long long i = T[pos].s; i < T[pos].f; i++) {
    if (V - T[pos].c * (a[i + 1] - a[i]) < 0) {
      return false;
    }
    if (tank - T[pos].c * (a[i + 1] - a[i]) < 0) {
      if (r > 0) {
        r--;
        tank = V;
      } else {
        return false;
      }
    }
    tank -= T[pos].c * (a[i + 1] - a[i]);
  }
  return true;
}
long long binarySearch(long long pos, long long ini, long long fin) {
  if (!isPossible(pos, fin)) return -1;
  if (isPossible(pos, ini)) return ini;
  while (fin - ini > 1) {
    long long med = (ini + fin) / 2;
    if (isPossible(pos, med)) {
      fin = med;
    } else {
      ini = med;
    }
  }
  return fin;
}
long long n, m;
vector<long long> indices;
long long minimumFill() {
  long long ini = 0;
  long long fin = 1e9;
  long long x = binarySearch(indices[0], ini, fin);
  for (long long i = 1; i < m; i++) {
    if (isPossible(indices[i], x)) {
      continue;
    }
    x = binarySearch(indices[i], x, fin);
  }
  return x;
}
void doit() {
  cin >> n >> m;
  for (long long i = 0; i < (long long)n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < (long long)m; i++) {
    cin >> T[i].s >> T[i].f >> T[i].c >> T[i].r;
    T[i].s--;
    T[i].f--;
    indices.push_back(i);
  }
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(indices.begin(), indices.end(), rng);
  cout << minimumFill() << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  doit();
  return 0;
}
