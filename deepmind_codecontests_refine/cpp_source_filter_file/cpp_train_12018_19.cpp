#include <bits/stdc++.h>
using namespace std;
int n;
int x, k, sol[100005];
bool sorted = 1;
int main() {
  cin >> n;
  while (n--) {
    cin >> x >> k;
    x++;
    if (sol[k] == x - 1)
      sol[k]++;
    else if (sol[k] > x)
      ;
    else
      sorted = 0;
  }
  cout << ((sorted == 1) ? "YES" : "NO");
  return 0;
}
