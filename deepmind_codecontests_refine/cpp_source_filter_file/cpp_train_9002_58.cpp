#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x1, y1, x2, y2;
  long long int answer = 0;
  cin >> n;
  while (n--) {
    cin >> x1 >> y1 >> x2 >> y2;
    answer += x2 - x1 + y2 - y1 + 2;
  }
  cout << answer << endl;
}
