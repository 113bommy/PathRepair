#include <bits/stdc++.h>
using namespace std;
int n;
int balance = 0;
vector<bool> arr;
int main() {
  cin >> n;
  arr.resize(n + 1, false);
  int p, q;
  cin >> p;
  for (int i = 0; i < p; i++) {
    int x;
    cin >> x;
    if (!arr[x]) {
      arr[x] = true;
      balance++;
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    if (!arr[x]) {
      arr[x] = true;
      balance++;
    }
  }
  if (balance == n)
    cout << "I become the guy." << endl;
  else
    cout << "Oh, my keyboard." << endl;
  return 0;
}
