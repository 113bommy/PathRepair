#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &first, T2 second) {
  if (first > second) first = second;
}
template <typename T1, typename T2>
inline void chkmax(T1 &first, T2 second) {
  if (first < second) first = second;
}
const string FILENAME = "input";
const int MAXN = 3001;
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int n;
int a[MAXN];
int b[MAXN];
vector<int> id;
bool cmp(int i, int j) { return a[i] < a[j]; }
int main() {
  srand(time(0));
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    id.push_back(i);
  }
  sort(id.begin(), id.end(), cmp);
  for (int i = 0; i < n; ++i) {
    b[id[i]] = a[id[(i + 1) % n]];
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] << ' ';
  }
  cout << endl;
}
