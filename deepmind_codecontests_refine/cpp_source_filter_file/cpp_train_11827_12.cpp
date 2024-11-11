#include <bits/stdc++.h>
using namespace std;
void affiche(int t[], int n) {
  for (int i = 0; i < n; i++) cout << t[i] << " ";
  cout << '\n';
}
void afficheV(vector<int> t) {
  for (int i = 0; i < t.size(); i++) cout << t[i] << " ";
  cout << '\n';
}
const long long MAXN = 1e5 + 5;
long long second, n;
long long t[MAXN];
long long b[MAXN];
long long find(int k) {
  long long second = 0;
  for (int i = 0; i < n; i++) b[i] = t[i] + (i + 1) * k;
  sort(b, b + n);
  for (int i = 0; i < k; i++) second += b[i];
  return second;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> second;
  for (int i = 0; i < n; i++) cin >> t[i];
  int l = 0, r = n + 1;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (find(mid) <= second)
      l = mid;
    else
      r = mid;
  }
  cout << l << " " << find(l) << '\n';
}
