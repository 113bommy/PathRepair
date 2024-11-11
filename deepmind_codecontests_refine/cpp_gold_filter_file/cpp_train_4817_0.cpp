#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n;
    priority_queue<int> q;
    while (n--) {
      cin >> k;
      q.push(k);
    }
    int t = 0, ht = 0;
    while (1) {
      t = q.top();
      t--;
      q.pop();
      q.push(ht);
      if (q.top() == 0) {
        cout << "T\n";
        break;
      }
      ht = q.top();
      ht--;
      q.pop();
      q.push(t);
      if (q.top() == 0) {
        cout << "HL\n";
        break;
      }
    }
  }
  return 0;
}
