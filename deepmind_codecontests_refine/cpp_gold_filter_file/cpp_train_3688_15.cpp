#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ranks[120];
  ranks[0] = 0;
  for (int i = 1; i < n; i++) cin >> ranks[i];
  int a, b;
  cin >> a >> b;
  b--;
  int sum = 0;
  for (int i = a; i <= b; i++) sum += ranks[i];
  cout << sum << endl;
}
