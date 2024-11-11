#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int input[n];
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }
  sort(input, input + n);
  vector<int> result;
  result.push_back(input[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    if (i % 2 == 0) {
      result.insert(result.begin(), input[i]);
    } else {
      result.push_back(input[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (result[i] != 0) cout << result[i] << " ";
  }
  cout << '\n';
  return 0;
}
