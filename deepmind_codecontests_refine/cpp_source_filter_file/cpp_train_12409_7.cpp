#include <bits/stdc++.h>
using namespace std;
bool b = 0;
void printUnique(int l, int r) {
  for (int i = l; i <= r; i++) {
    int num = i;
    bool visited[10] = {false};
    while (num) {
      if (visited[num % 10]) break;
      visited[num % 10] = true;
      num = num / 10;
    }
    if (num == 0) {
      cout << i << " ";
      b = 1;
      return;
    }
  }
}
int main() {
  int a, b;
  cin >> a >> b;
  printUnique(a, b);
  if (b == 0) {
    cout << -1;
  }
}
