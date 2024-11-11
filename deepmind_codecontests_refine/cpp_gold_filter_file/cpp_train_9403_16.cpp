#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, place, num = 0, s;
  cin >> n;
  cin >> place;
  int list_1[n];
  for (int i = 0; i < n; i++) {
    cin >> list_1[i];
  }
  sort(list_1, list_1 + n);
  reverse(list_1, list_1 + n);
  for (int i = 0; i < n; i++) {
    if (list_1[i] >= list_1[place - 1]) {
      num++;
    }
    if (list_1[i] < list_1[place - 1]) {
      break;
    }
  }
  s = num - 1;
  for (int i = s; i >= 0; i--) {
    if (list_1[i] == 0) {
      num--;
    }
  }
  cout << num;
}
