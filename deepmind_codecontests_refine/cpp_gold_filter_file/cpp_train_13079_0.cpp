#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;
const long long inf = 1e18 + 100;
long double EPS = 1e-18;
const int INF = 2000000000;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int dxx[] = {0, 0, -1, -1, -1, 1, 1, 1};
int dyy[] = {1, -1, 0, 1, -1, 0, 1, -1};
bool valid(int x, int y, int nn, int mm) {
  return (x >= 0 && y >= 0 && x < nn && y < mm);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  vector<int> pows;
  for (int i = 0; i < 63; i++)
    if ((1ll << i) & n) pows.push_back(i);
  if (pows.size() > k) return cout << "No", 0;
  cout << "Yes" << endl;
  while (pows.size() < k) {
    int x = pows.back(), cnt = 0;
    while (pows.size() && pows.back() == x) pows.pop_back(), cnt++;
    if (pows.size() + 2 * cnt <= k)
      while (cnt--) pows.push_back(x - 1), pows.push_back(x - 1);
    else {
      while (cnt--) pows.push_back(x);
      break;
    }
  }
  reverse(pows.begin(), pows.end());
  while (pows.size() < k) {
    int x = pows.back();
    pows.pop_back();
    pows.push_back(x - 1);
    pows.push_back(x - 1);
  }
  sort(pows.rbegin(), pows.rend());
  for (int i = 0; i < k; i++) cout << pows[i] << ' ';
  return 0;
}
