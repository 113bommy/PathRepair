#include <bits/stdc++.h>
using namespace std;
map<string, bool> mp;
int n, k;
int check(int mid) {
  int temp = 1;
  long long int ans = 0;
  while (mid / temp) {
    ans += mid / temp;
    temp = temp * k;
  }
  return ans;
}
int main() {
  int n;
  vector<int> right;
  vector<int> a;
  vector<int> left;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    right.push_back(1e9);
    left.push_back(1e9);
  }
  if (a[0] == 0) left[0] = 0;
  for (int i = 1; i < n; i++) {
    if (!a[i])
      left[i] = i;
    else
      left[i] = left[i - 1];
  }
  if (a[n - 1] == 0) right[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (!a[i])
      right[i] = i;
    else
      right[i] = right[i + 1];
  }
  for (int i = 0; i < n; i++) {
    cout << min(abs(left[i] - i), abs(right[i] - i)) << " ";
  }
}
