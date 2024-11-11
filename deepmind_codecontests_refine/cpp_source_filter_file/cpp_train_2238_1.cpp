#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream &operator<<(ostream &out, pair<S, T> const &p) {
  out << p.first << " " << p.second;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> const &v) {
  long long int l = v.size();
  for (long long int i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char *name, T &&arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename T, typename... Args>
void trace(const char *names, T &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
long long int BLOCK_SIZE;
bool cmp(const pair<pair<int, int>, int> &a,
         const pair<pair<int, int>, int> &b) {
  return a.first.first < b.first.first ||
         (a.first.first == b.first.first &&
          (a.first.first % 2 == 0 ? (a.first.second < b.first.second)
                                  : (a.first.second > b.first.second)));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  BLOCK_SIZE = 1000;
  vector<pair<pair<long long, long long>, long long int>> v;
  for (long long int i = 0; i < n; i++) {
    long long int x, y;
    cin >> x >> y;
    v.push_back(make_pair(make_pair(x, y), i + 1));
    v[i].first.second /= BLOCK_SIZE;
  }
  sort(v.begin(), v.end(), cmp);
  for (long long int i = 0; i < n; i++) {
    cout << v[i].second << ' ';
  }
  return 0;
}
