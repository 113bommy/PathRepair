#include <bits/stdc++.h>
using namespace std;
struct xy {
  int x, y;
};
int main() {
  xy ms[3];
  for (int i = 0; i < 3; i++) scanf("%d%d", &ms[i].x, &ms[i].y);
  if (((ms[1].x * 1ll * ms[2].y - ms[1].y * 1ll * ms[2].x) -
       (ms[0].x * 1ll * ms[2].y - ms[0].y * 1ll * ms[2].x) +
       (ms[0].x * 1ll * ms[1].y - ms[1].x * 1ll * ms[0].y)) > 0)
    cout << "LEFT" << endl;
  else if (((ms[1].x * 1ll * ms[2].y - ms[1].y * 1ll * ms[2].x) -
            (ms[0].x * 1ll * ms[2].y - ms[0].y * 1ll * ms[2].x) +
            (ms[0].x * 1ll * ms[1].y - ms[1].x * 1ll * ms[0].y)) < 0)
    puts("RIGHT");
  else
    puts("TOWARD");
}
