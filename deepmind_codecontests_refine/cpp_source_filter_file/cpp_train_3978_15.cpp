#include <bits/stdc++.h>
using namespace ::std;
const long long maxn = 30010;
const long long mod = 1e15 + 7;
long long a[maxn];
bool mark[maxn];
bool ok[maxn];
void gos(long long n, long long d, long long h) {
  long long last = h;
  memset(mark, 0, sizeof(mark));
  for (long long i = 0; i < n - 2; i++) {
    if (last == a[i]) {
      mark[i] = 1;
      last += d;
    }
    if (i == 0) {
      ok[i] = mark[i];
    } else {
      ok[i] = (ok[i - 1] & mark[i]);
    }
  }
  d = (a[n - 1] - a[n - 2]);
  long long ex = a[n - 2] - d;
  bool jelo = 0;
  for (long long i = n - 3; i >= 0; i++) {
    if (ok[i]) {
      break;
    }
    if (a[i] == ex) {
      if (mark[i] && jelo) {
        return;
      }
      mark[i] = 0;
      ex -= d;
    } else {
      if (mark[i]) {
        jelo = 1;
      } else {
        return;
      }
    }
  }
  d = 0;
  for (long long i = 0; i < n; i++) d += mark[i];
  if (d == n || d == 0) {
    mark[0] = !mark[0];
  }
  for (long long i = 0; i < n; i++) {
    if (mark[i]) {
      cout << a[i] << ' ';
    }
  }
  cout << endl;
  for (long long i = 0; i < n; i++) {
    if (!mark[i]) {
      cout << a[i] << ' ';
    }
  }
  cout << endl;
  exit(0);
}
void god(long long n, long long d, long long h) {
  long long last = h;
  memset(mark, 0, sizeof(mark));
  for (long long i = 0; i < n; i++) {
    if (last == a[i]) {
      mark[i] = 1;
      last += d;
    }
  }
  last = -mod;
  d = -mod;
  for (long long i = 0; i < n; i++) {
    if (!mark[i]) {
      if (last == -mod) {
        last = a[i];
      } else {
        if (d == -mod) {
          d = a[i] - last;
          last = a[i];
        } else {
          if (a[i] != last + d) {
            return;
          } else {
            last = a[i];
          }
        }
      }
    }
  }
  d = 0;
  for (long long i = 0; i < n; i++) d += mark[i];
  if (d == n || d == 0) {
    mark[0] = !mark[0];
  }
  for (long long i = 0; i < n; i++) {
    if (mark[i]) {
      cout << a[i] << ' ';
    }
  }
  cout << endl;
  for (long long i = 0; i < n; i++) {
    if (!mark[i]) {
      cout << a[i] << ' ';
    }
  }
  cout << endl;
  exit(0);
}
void good(long long n, long long d) {
  god(n, d, a[0]);
  god(n, d, a[1]);
  gos(n, d, a[0]);
  gos(n, d, a[1]);
}
map<long long, long long> ml;
vector<pair<long long, long long> > vec;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 2) {
    cout << a[0] << '\n' << a[1] << endl;
    return 0;
  }
  set<long long> st;
  for (long long i = 0; i + 2 < n; i++) {
    ml[a[i + 1] - a[i]]++;
    ml[a[i + 2] - a[i]]++;
    ml[a[i + 2] - a[i + 1]]++;
    st.insert(a[i + 1] - a[i]);
    st.insert(a[i + 2] - a[i]);
    st.insert(a[i + 2] - a[i + 1]);
  }
  vector<pair<long long, long long> > vec;
  while (st.size()) {
    long long v = (*st.begin());
    st.erase(v);
    vec.push_back(make_pair(-ml[v], v));
  }
  god(n, a[1] - a[0], a[0]);
  gos(n, a[1] - a[0], a[0]);
  sort(vec.begin(), vec.end());
  for (long long i = 0; i < min((long long)vec.size(), (long long)6); i++) {
    good(n, vec[i].second);
  }
  cout << "No solution";
}
