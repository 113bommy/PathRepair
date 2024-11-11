#include <bits/stdc++.h>
using namespace std;
template <typename Type>
void print_array(Type* array, int start, int end);
template <typename Type>
void print_vector(vector<Type> v);
long long uf[100100], rk[100100], sz[100100];
long long a[100100], n, ord[100100];
bitset<100100> bs;
vector<long long> ans;
int find(int x) { return x == uf[x] ? uf[x] : find(uf[x]); }
void join(int i, int j) {
  int x = find(i);
  int y = find(j);
  if (rk[x] > rk[y]) {
    uf[y] = x;
    sz[x] += sz[y];
  } else {
    uf[x] = y;
    if (rk[x] == rk[y]) rk[y]++;
    sz[y] += sz[x];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = (0), _b = (n); i < _b; i++) {
    cin >> a[i];
    sz[i + 1] = a[i];
  }
  memset(rk, 0, sizeof rk);
  for (int i = (0), _b = (n + 1); i < _b; i++) uf[i] = i;
  bs.reset();
  for (int i = (1), _b = (n + 1); i < _b; i++) {
    cin >> ord[i];
  }
  int best = 0;
  for (int i = n; i > 0; i--) {
    bs[ord[i]] = 1;
    if (bs[ord[i] + 1]) {
      join(ord[i] + 1, ord[i]);
    }
    if (bs[ord[i] - 1]) {
      join(ord[i] - 1, ord[i]);
    }
    if (sz[find(ord[i])] > best) {
      best = sz[find(ord[i])];
    }
    ans.push_back(best);
  }
  reverse((ans).begin(), (ans).end());
  for (int i = 1; i < n; i++) {
    cout << ans[i] << endl;
  }
  cout << 0 << endl;
  return 0;
}
template <typename Type>
void print_array(Type* array, int start, int end) {
  cout << "[";
  for (int i = (start), _b = (end); i < _b; i++) {
    cout << array[i] << " ";
  }
  cout << "]\n";
}
template <typename Type>
void print_vector(vector<Type> v) {
  cout << "[";
  for (int i = (0), _b = ((int)(v).size()); i < _b; i++) {
    cout << v[i] << " ";
  }
  cout << "]\n";
}
