#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<bool> numbers(n + 1, false);
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    numbers[a] = true;
  }
  int answer;
  for (int i = 1; i < n; i++) {
    if (numbers[i] == false) {
      answer = i;
      break;
    }
  }
  cout << answer << "\n";
  return 0;
}
