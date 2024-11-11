#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> array(n);
  for (int i = 0; i < n; i++) cin >> array[i];
  sort(array.begin(), array.end());
  long long result = 0;
  for (int i = 0; i < n; i++) result += abs(i + 1 - array[i]);
  cout << result;
  return 0;
}
