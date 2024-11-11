#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long mini = min(a, b);
  long long ans = 0;
  if (mini = a)
    ans = (b - a) / 2;
  else
    ans = (a - b) / 2;
  cout << mini << " " << ans;
}
