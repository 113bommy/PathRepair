#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b != 0)
    return gcd(b, a % b);
  else
    return a;
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0) {
    long long int t = power(a, b / 2);
    return t * t;
  } else {
    long long int t = power(a, b / 2);
    return a * t * t;
  }
}
long long int powin(long long int a, long long int b) {
  if (b == 0)
    return 1;
  else if (b == 1)
    return a;
  else if (b % 2 == 0) {
    long long int t = powin(a, b / 2);
    return (t * t) % 1000000007;
  } else {
    long long int t = powin(a, b / 2);
    return (((t * t) % 1000000007) * a) % 1000000007;
  }
}
long long int n, m, k, x, y, z, p, cnt;
long long int ans = 0;
long long int c[500009];
map<long long int, vector<long long int> > sz;
unordered_set<long long int> st;
int Arr[500009];
int size[500009];
void initialize() {
  for (int i = 0; i < 500009; i++) {
    Arr[i] = i;
    size[i] = 1;
  }
}
int root(int i) {
  while (Arr[i] != i) {
    Arr[i] = Arr[Arr[i]];
    i = Arr[i];
  }
  return i;
}
void uni(int A, int B) {
  int root_A = root(A);
  int root_B = root(B);
  if (size[root_A] < size[root_B]) {
    Arr[root_A] = Arr[root_B];
    size[root_B] += size[root_A];
  } else {
    Arr[root_B] = Arr[root_A];
    size[root_A] += size[root_B];
  }
}
int main() {
  initialize();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> n >> m >> k;
  ans = powin(2, n + k);
  for (long long int i = 1; i < n + 1; i++) {
    cin >> c[i];
  }
  for (long long int i = 0; i < m; i++) {
    cin >> x >> y;
    z = c[x] ^ c[y];
    st.insert(z);
    sz[z].push_back(x);
    sz[z].push_back(y);
  }
  ans = (((ans - ((st.size() * powin(2, n)) % 1000000007)) + 1000000007) %
         1000000007);
  for (auto it : st) {
    p = it;
    cnt = 0;
    set<long long int> s;
    for (int i = 0; i < sz[p].size(); i += 2) {
      uni(sz[p][i], sz[p][i + 1]);
      s.insert(sz[p][i]);
      s.insert(sz[p][i + 1]);
    }
    for (auto it : s) {
      if (Arr[(int)it] == (int)it) cnt++;
      Arr[(int)it] = it;
    }
    ans = ((ans + powin(2, cnt + n - s.size())) % 1000000007);
  }
  cout << ans << endl;
  return 0;
}
