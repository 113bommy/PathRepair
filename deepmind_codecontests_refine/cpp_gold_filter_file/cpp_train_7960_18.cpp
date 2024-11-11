#include <bits/stdc++.h>
using namespace std;
void display(std::vector<int> v) {
  for (int i = 3; i >= 0; i--) {
    for (int j = 0; j < v[i]; j++) {
      if (i == 3)
        cout << 7;
      else if (i == 2)
        cout << 5;
      else if (i == 1)
        cout << 3;
      else if (i == 0)
        cout << 2;
    }
  }
}
int main() {
  int n;
  cin >> n;
  std::vector<int> v = {0, 0, 0, 0};
  while (n--) {
    char c;
    cin >> c;
    if (c == '2')
      v[0]++;
    else if (c == '3')
      v[1]++;
    else if (c == '4') {
      v[0] += 2;
      v[1]++;
    } else if (c == '5')
      v[2]++;
    else if (c == '6') {
      v[1] += 1;
      v[2]++;
    } else if (c == '7')
      v[3]++;
    else if (c == '8') {
      v[3]++;
      v[0] += 3;
    } else if (c == '9') {
      v[1] += 2;
      v[0]++;
      v[3]++;
    }
  }
  display(v);
  return 0;
}
