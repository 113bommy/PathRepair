#include <bits/stdc++.h>
using namespace std;
int n = 0;
int a[200010];
int v[200010];
int last = -1;
int main(int argc, const char* argv[]) {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    v[a[i]] = -1;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (v[a[i]] == -1) {
      v[a[i]] = 1;
      last = a[i];
    }
  }
  cout << last << endl;
  return 0;
}
