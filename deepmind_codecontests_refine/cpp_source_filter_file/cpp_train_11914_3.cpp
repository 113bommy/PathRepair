#include <bits/stdc++.h>
using namespace std;
bool ada[105];
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  memset(ada, -1, sizeof ada);
  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    ada[x] = 1;
  }
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
  }
  for (int i = 1; i <= n; i++) {
    if (ada[i]) {
      cout << 1 << " ";
    } else
      cout << 2 << " ";
  }
  cout << endl;
}
