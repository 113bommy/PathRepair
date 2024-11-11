#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int websites[100];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> websites[i];
    sum = sum + websites[i];
  }
  int answer = 0;
  int index;
  int temp;
  for (int i = 0; i < k; i++) {
    index = i;
    temp = sum;
    while (index < n) {
      temp = temp - websites[index];
      index = index + k;
    }
    if (abs(temp) > abs(answer)) answer = temp;
  }
  cout << abs(answer);
  return 0;
}
