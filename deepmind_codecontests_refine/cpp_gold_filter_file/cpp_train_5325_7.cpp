#include <bits/stdc++.h>
using namespace std;
const int limit = 100;
int n;
int amount[limit];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    amount[x]++;
  }
  int i = 0;
  while (not amount[i]) i++;
  if (2 * amount[i] > n)
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;
}
