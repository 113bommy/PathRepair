#include <bits/stdc++.h>
using namespace std;
bool Check(int i) {
  int p;
  int Sum = 0;
  while (i > 0) {
    p = i % 10;
    Sum += p;
    i /= 10;
  }
  if (Sum % 4 == 0) {
    return 1;
  } else {
    return 0;
  }
}
int a;
void Read() {
  cin >> a;
  for (int i = a; i <= 1010; i++) {
    if (Check(i) == 1) {
      cout << i;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  Read();
  return 0;
}
