#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  while (n--) {
    int answer = 0, d = -1;
    string order;
    cin >> order;
    order.push_back('R');
    for (int i = 0; i <= order.size(); i++) {
      if (order[i] == 'R') {
        if (answer < i - d) answer = i - d;
        d = i;
      }
    }
    cout << answer << endl;
  }
}
