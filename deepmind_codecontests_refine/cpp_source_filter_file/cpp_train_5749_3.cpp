#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    memset(b, -1, sizeof(b));
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i]) {
        b[a[i] - 1] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (b[i] == -1) {
        v.push_back(i + 1);
      }
    }
    sort(v.rbegin(), v.rend());
    int q = 0, m = 0;
    for (int i = 0; i < n; i++) {
      if (!a[i]) {
        if (v[q] == i + 1 && q != v.size() - 1)
          swap(v[q], v[q + 1]);
        else if (v[q] == i + 1 && q == v.size())
          swap(v[q], v[q - 1]);
        q++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!a[i]) {
        cout << v[m++] << ' ';
      } else {
        cout << a[i] << ' ';
      }
    }
  }
}
