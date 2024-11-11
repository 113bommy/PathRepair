#include <bits/stdc++.h>
using namespace std;
long long int n, l, m, cnt, ans, one = 1, mx, mn;
int sum;
int a[10000001];
string s;
set<long long int> se;
vector<long long int> v;
float arr[10000001];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (a[n - 1] == 1) {
    for (int i = 0; i < n - 1; i++) {
      cout << a[i] << " ";
    }
    cout << a[n - 1] + 1;
  } else {
    cout << 1 << " ";
    for (int i = 0; i < n - 1; i++) {
      cout << a[i] << " ";
    }
  }
}
