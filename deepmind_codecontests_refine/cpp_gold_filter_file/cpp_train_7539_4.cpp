#include <bits/stdc++.h>
using namespace std;
const int N = 4000009;
int main() {
  string a, b;
  char upperbound = 'a';
  cin >> a >> b;
  int lt1[124] = {0}, lt2[124] = {0};
  for (int i = 0; i < a.size(); i++) {
    lt1[a[i]]++;
  }
  for (int i = 0; i < b.size(); i++) {
    lt2[b[i]]++;
    if (b[i] > upperbound) {
      upperbound = b[i];
    }
  }
  int count = 0;
  for (char i = 'a'; i <= upperbound; i++) {
    if (lt2[i] > 0 && lt1[i] == 0) {
      cout << -1;
      return 0;
    }
    if (lt1[i] >= lt2[i]) {
      count += lt2[i];
    } else {
      count += lt1[i];
    }
  }
  cout << count;
  return 0;
}
