#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<unsigned long long> a(n), b(n);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    unsigned long long x;
    cin >> x;
    a[i] = x;
  }
  for (int i = 0; i < n; i++) {
    unsigned long long x;
    cin >> x;
    b[i] = x;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    int j;
    for (j = i + 1; j < n; j++) {
      if (a[j] == b[i]) {
        break;
      }
    }
    for (; j > i; j--) {
      swap(a[j], a[j - 1]);
      q.push(j + 1);
    }
  }
  cout << q.size() << endl;
  while (!q.empty()) {
    cout << q.front() - 1 << " " << q.front() << endl;
    q.pop();
  }
  return 0;
}
