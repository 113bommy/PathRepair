#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[1002];
int counter = 0;
queue<int> q;
void print(int l, int r) {
  counter += (r - l + 1);
  for (int i = l; i <= r; i++) q.push(i);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + n);
  int curr = 1;
  for (int i = 0; i < n; i++) {
    if (curr < a[i].first) print(curr, a[i].first - 1);
    if (curr < a[i].second) curr = a[i].second + 1;
  }
  print(curr, m);
  cout << counter << endl;
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
  return 0;
}
