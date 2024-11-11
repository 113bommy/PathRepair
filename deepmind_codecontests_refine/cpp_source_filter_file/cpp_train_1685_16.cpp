#include <bits/stdc++.h>
using namespace std;
int main() {
  stack<int> s;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      int k;
      cin >> k;
      s.push(k);
    }
    int count = 0;
    int min = s.top();
    s.pop();
    while (!s.empty()) {
      int temp = s.top();
      if (temp < min)
        min = temp;
      else
        count++;
      s.pop();
    }
    cout << count << endl;
  }
  return 0;
}
