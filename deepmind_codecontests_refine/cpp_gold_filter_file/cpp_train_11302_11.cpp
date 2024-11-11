#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b;
  char ch;
} temp;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  node save[8];
  for (int i = 0; i < 8; i++) {
    save[i].ch = 't';
  }
  for (int i = 0; i < n; i++) {
    cin >> temp.ch >> temp.a >> temp.b;
    if (temp.a == x && temp.b > y && (save[2].ch == 't' || save[2].b > temp.b))
      save[2] = temp;
    else if (temp.a == x && temp.b < y &&
             (save[3].ch == 't' || save[3].b < temp.b))
      save[3] = temp;
    else if (temp.b == y && temp.a > x &&
             (save[0].ch == 't' || save[0].a > temp.a))
      save[0] = temp;
    else if (temp.b == y && temp.a < x &&
             (save[1].ch == 't' || save[1].a < temp.a))
      save[1] = temp;
    else if (abs(temp.a - x) == abs(temp.b - y)) {
      if (temp.a - x > 0 && temp.b - y > 0 &&
          (save[4].ch == 't' || save[4].a > temp.a))
        save[4] = temp;
      else if (temp.a - x > 0 && temp.b - y < 0 &&
               (save[5].ch == 't' || save[5].a > temp.a))
        save[5] = temp;
      else if (temp.a - x < 0 && temp.b - y > 0 &&
               (save[6].ch == 't' || save[6].a < temp.a))
        save[6] = temp;
      else if (temp.a - x < 0 && temp.b - y < 0 &&
               (save[7].ch == 't' || save[7].a < temp.a))
        save[7] = temp;
    }
  }
  bool flag = false;
  for (int i = 0; i < 4; i++) {
    if (save[i].ch == 'R' || save[i].ch == 'Q') flag = true;
  }
  for (int i = 4; i < 8; i++) {
    if (save[i].ch == 'B' || save[i].ch == 'Q') flag = true;
  }
  if (flag == true)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
