#include <bits/stdc++.h>
using namespace std;
void file() { freopen("in.txt", "r", stdin); }
bool flag[3005];
int main() {
  int n;
  scanf("%d", &n);
  int temp;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &temp);
    flag[temp] = 1;
  }
  for (int i = 1; i <= 3001; ++i) {
    if (flag[i] == 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
