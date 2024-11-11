#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  int n, k;
  int flag[2 * 50000 + 100];
  cin >> n >> k;
  for (int i = 1; i <= 2 * n; i++) flag[i] = i;
  int i = 1;
  while (k--) {
    swap(flag[2 * i - 1], flag[2 * i + 1]);
    i++;
  }
  for (int i = 1; i <= 2 * n; i++) cout << flag[i] << " ";
  return 0;
}
