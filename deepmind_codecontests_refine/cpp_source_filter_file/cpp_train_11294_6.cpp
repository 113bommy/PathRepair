#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n; i++) cin >> num[i], num[i] += i;
  sort(num.begin(), num.end());
  for (int i = 1; i < n; i++)
    if (num[i] == num[i - 1]) return cout << ":(", 0;
  for (int i = 0; i < n; i++) cout << num[i] - i;
  return 0;
}
