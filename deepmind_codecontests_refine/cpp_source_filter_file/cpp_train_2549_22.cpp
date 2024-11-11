#include <bits/stdc++.h>
using namespace std;
int main() {
  char x[1000];
  cin >> x;
  int result = 0;
  for (int i = 0; i < strlen(x) + 1; i++) {
    result += 25;
  }
  cout << result;
}
