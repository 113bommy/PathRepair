#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> q;
long long n, a, i, j, t[100050], b, c;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    q.push(a);
  }
  j = n - 1;
  for (int k = 0; k < n; k++) {
    if (k & 1) {
      t[j] = q.top();
      j--;
    } else {
      t[i] = q.top();
      i++;
    }
    q.pop();
  }
  for (int i = 0; i < n; i++) {
    a = t[(a + n - 1) % n], b = t[i], c = t[(i + 1) % n];
    if (a + c <= b) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << t[i] << ' ';
  }
}
