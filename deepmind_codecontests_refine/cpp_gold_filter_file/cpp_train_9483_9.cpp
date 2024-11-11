#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
int a, c;
int arrA[2000];
int arrC[2000];
void sol() {
  cin >> c >> a;
  for (int i = 0; i < c; i++) {
    cin >> arrC[i];
  }
  for (int i = 0; i < a; i++) {
    cin >> arrA[i];
  }
  int result = 0;
  int j = 0;
  for (int i = 0; i < a && j < c; i++, j++) {
    while (j < c && arrC[j] > arrA[i]) j++;
    if (j >= c) break;
    result++;
  }
  cout << result << endl;
}
int main(void) {
  sol();
  return 0;
}
