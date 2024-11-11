#include <bits/stdc++.h>
using namespace std;
int chart[30];
int num[120005];
map<int, int> check;
int main() {
  int n, answer, mark;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    if (check[num[i]] != 0) {
      check[num[i]] = 1000000005;
    } else {
      check[num[i]] = i + 1;
    }
  }
  chart[0] = 1;
  for (int i = 1; i < 31; i++) {
    chart[i] = chart[i - 1] * 2;
  }
  answer = 0;
  for (int i = 0; i < n; i++) {
    mark = 0;
    for (int j = 0; j < 31; j++) {
      if (check[chart[j] - num[i]] != 0 && check[chart[j] - num[i]] != i + 1) {
        mark = 1;
        break;
      }
    }
    if (mark == 0) {
      answer++;
    }
  }
  cout << answer << endl;
  return 0;
}
