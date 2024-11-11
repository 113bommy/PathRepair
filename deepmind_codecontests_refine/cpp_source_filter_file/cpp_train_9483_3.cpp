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
  for (int i = 0; i < c && j < a; i++, j++) {
    while (j < a && arrC[i] > arrA[j]) j++;
    if (j >= a) break;
    result++;
  }
  cout << result << endl;
}
int main(void) {
  sol();
  return 0;
}
