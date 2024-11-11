#include <bits/stdc++.h>
using namespace std;
int main() {
  char s;
  vector<int> v1;
  int kol1 = 0;
  while (cin.get(s)) {
    if (s != '\n') {
      v1.push_back(s - '0');
      if (s == '1') ++kol1;
    }
  }
  int num4 = v1.size() / 2 + v1.size() % 2;
  if (v1.size() % 2 == 1 && kol1 <= 1) {
    --num4;
  }
  cout << num4;
}
