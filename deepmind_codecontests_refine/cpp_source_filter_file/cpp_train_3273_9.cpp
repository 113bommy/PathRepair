#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ac[100000], hcc[100001] = {0};
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    hcc[tmp]++;
    cin >> tmp;
    ac[i] = tmp;
  }
  for (int i = 0; i < n; i++)
    cout << n - 1 + hcc[ac[i]] << n - 1 - hcc[ac[i]] << endl;
  return 0;
}
