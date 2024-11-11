#include <bits/stdc++.h>
using namespace std;
struct Room {
  int length, width, height;
  Room() {}
};
struct Wallpaper {
  int length, width, price;
  Wallpaper() {}
};
int main() {
  int N, M;
  scanf("%d", &N);
  vector<Room> r(N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &r[i].length, &r[i].width, &r[i].height);
  }
  scanf("%d", &M);
  vector<Wallpaper> w(M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &w[i].length, &w[i].width, &w[i].price);
  }
  int m = 0;
  for (int i = 0; i < N; i++) {
    int mp = 1 << 25;
    int perimeter = (r[i].length + r[i].width) * 2;
    for (int j = 0; j < M; j++) {
      int tmp = (w[j].length / r[i].height) * w[j].width;
      if (tmp) {
        mp = min(mp, ((perimeter + (tmp - 1)) / tmp * w[j].price));
      }
    }
    m += mp;
  }
  printf("%d\n", m);
  return 0;
}
