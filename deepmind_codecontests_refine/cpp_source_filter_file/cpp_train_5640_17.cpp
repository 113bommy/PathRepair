#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int a, b;
int num[maxn];
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    num[a]++;
    num[b]++;
  }
  int flag = 1;
  for (int i = 0; i < n; i++) {
    if (num[i] == 2) {
      cout << "NO" << endl;
      flag = 0;
      break;
    }
  }
  if (flag == 1) cout << "YES" << endl;
}
