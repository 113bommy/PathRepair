#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167772160000")
using namespace std;
vector<int> LIS;
int addToLIS(int a) {
  int low = 0;
  int high = LIS.size();
  while (low < high) {
    int mid = (low + high) / 2;
    if (LIS[mid] <= a)
      low = mid + 1;
    else
      high = mid;
  }
  if (low == LIS.size()) LIS.push_back(0);
  LIS[low] = a;
  return low + 1;
}
int answers[110000];
int a[110000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (n); i++) {
    int l, r;
    cin >> l >> r;
    a[l]++;
    a[r + 1]--;
  }
  for (int i = 1; i <= (m); i++) a[i] += a[i - 1];
  for (int i = 1; i <= (m); i++) answers[i] += addToLIS(a[i]);
  LIS.clear();
  for (int i = m; i >= 1; i--) answers[i] += addToLIS(a[i]);
  int answer = 0;
  for (int i = 1; i <= (m); i++) answer = max(answer, answers[i] - 1);
  cout << answer << endl;
  return 0;
}
