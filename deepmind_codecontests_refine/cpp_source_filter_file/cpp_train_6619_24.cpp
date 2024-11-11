#include <bits/stdc++.h>
using namespace std;
long long int Ans, cnt, check[100000];
int main() {
  int n;
  cin >> n;
  n *= 2;
  while (n--) {
    int a;
    cin >> a;
    if (check[a] == 1)
      cnt--;
    else
      check[a] = 1, Ans = max(++cnt, Ans);
  }
  return cout << Ans << endl, EXIT_SUCCESS;
}
