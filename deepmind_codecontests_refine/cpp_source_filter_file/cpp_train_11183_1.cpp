#include <bits/stdc++.h>
using namespace std;
int main() {
  int count;
  cin >> count;
  int data[1001] = {};
  int max = 0;
  for (int i = 0; i < count; i++) {
    int input;
    cin >> input;
    data[input]++;
    if (input > max) max = input;
  }
  int time;
  cin >> time;
  max = 0;
  for (int i = 0; i < 1000 - time; i++) {
    int sum = 0;
    for (int j = i; j < i + time + 1; j++) sum += data[j];
    if (sum > max) max = sum;
  }
  cout << max << endl;
  return 0;
}
