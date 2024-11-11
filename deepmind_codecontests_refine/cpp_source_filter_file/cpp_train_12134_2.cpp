#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 100010;
long long a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int num = 1;
  int maxx = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      num++;
      maxx = max(maxx, num);
    } else
      num = 1;
  }
  cout << maxx << endl;
}
