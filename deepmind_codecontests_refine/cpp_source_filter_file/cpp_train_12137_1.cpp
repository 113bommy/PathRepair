#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
bool comp(int a1, int b1) { return a[a1] > a[b1]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, sum = 0, now;
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = i;
    sum += a[i];
  }
  if (sum < n || a[0] == 0) {
    cout << "-1";
    return 0;
  }
  sort(b.begin() + 1, b.end(), comp);
  l = 1;
  now = 0;
  cout << n - 1 << "\n";
  while (l < n) {
    while (a[b[now]] <= 0) now++;
    cout << b[now] + 1 << " " << b[l] + 1 << "\n";
    l++;
    a[b[now]]--;
  }
}
