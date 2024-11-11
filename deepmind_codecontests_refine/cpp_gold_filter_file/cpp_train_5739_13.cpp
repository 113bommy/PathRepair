#include <bits/stdc++.h>
using namespace std;
int n, a[100010], nb, na;
struct Info {
  int x, y, z;
} b[30], an[100010];
void co(int x, int y) {
  an[++na].x = x;
  an[na].y = x + y;
  an[na].z = x + y + y;
  a[x] ^= 1;
  a[x + y] ^= 1;
  a[x + y + y] ^= 1;
}
void work1(int l, int r) {
  for (int i = 1; i <= 10; i++)
    for (int j = l; j + i + i <= r; j++) {
      b[nb].x = j;
      b[nb].y = j + i;
      b[nb].z = j + i + i;
      nb++;
    }
  for (int i = 0; i < (1 << nb); i++) {
    for (int j = 0; j < nb; j++) {
      if ((i & (1 << j)) != 0) {
        a[b[j].x] ^= 1;
        a[b[j].y] ^= 1;
        a[b[j].z] ^= 1;
      }
    }
    bool c = true;
    for (int j = l; j <= r; j++) {
      if (a[j] == 1) c = false;
    }
    if (c) {
      cout << "YES" << endl;
      for (int j = 0; j < nb; j++)
        if ((i & (1 << j)) != 0) co(b[j].x, b[j].y - b[j].x);
      return;
    }
    for (int j = 0; j < nb; j++) {
      if ((i & (1 << j)) != 0) {
        a[b[j].x] ^= 1;
        a[b[j].y] ^= 1;
        a[b[j].z] ^= 1;
      }
    }
  }
  cout << "NO" << endl;
  exit(0);
}
void work(int l, int r) {
  for (int i = 1; i <= 10; i++)
    for (int j = l; j + i + i <= r; j++) {
      b[nb].x = j;
      b[nb].y = j + i;
      b[nb].z = j + i + i;
      nb++;
    }
  for (int i = 0; i < (1 << nb); i++) {
    for (int j = 0; j < nb; j++) {
      if ((i & (1 << j)) != 0) {
        a[b[j].x] ^= 1;
        a[b[j].y] ^= 1;
        a[b[j].z] ^= 1;
      }
    }
    bool c = true;
    for (int j = l; j <= r; j++) {
      if (a[j] == 1) c = false;
    }
    if (c) {
      for (int j = 0; j < nb; j++)
        if ((i & (1 << j)) != 0) co(b[j].x, b[j].y - b[j].x);
      return;
    }
    for (int j = 0; j < nb; j++) {
      if ((i & (1 << j)) != 0) {
        a[b[j].x] ^= 1;
        a[b[j].y] ^= 1;
        a[b[j].z] ^= 1;
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n <= 8) {
    work1(1, n);
  } else {
    cout << "YES" << endl;
    int no = 1;
    while (n - no + 1 > 10) {
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        ;
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no + 5, 1);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no + 4, 2);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no + 4, 1);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no + 3, 1);
        co(no + 4, 1);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no + 3, 2);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no + 3, 1);
        co(no + 5, 1);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no + 3, 1);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no + 2, 2);
        co(no + 4, 2);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no + 2, 3);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no + 2, 2);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no + 2, 2);
        co(no + 5, 1);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no + 2, 1);
        co(no + 4, 2);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no + 2, 1);
        co(no + 4, 1);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no + 2, 1);
      }
      if (a[no] == 0 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no + 2, 1);
        co(no + 5, 1);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no + 1, 2);
        co(no + 3, 2);
        ;
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no + 1, 3);
        co(no + 4, 1);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no + 1, 3);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no + 1, 3);
        co(no + 5, 1);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no + 1, 2);
        co(no + 5, 1);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no + 1, 2);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no + 1, 2);
        co(no + 4, 1);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no + 1, 2);
        co(no + 4, 2);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no + 1, 3);
        co(no + 2, 2);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no + 1, 1);
        co(no + 3, 2);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no, 1);
        co(no, 4);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no + 1, 1);
        co(no + 3, 1);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no + 1, 1);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no + 1, 1);
        co(no + 5, 1);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no + 1, 1);
        co(no + 4, 2);
      }
      if (a[no] == 0 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no + 1, 1);
        co(no + 4, 1);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no, 2);
        co(no + 2, 2);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no, 3);
        co(no + 3, 2);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no, 4);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no, 4);
        co(no + 5, 1);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no, 3);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no, 3);
        co(no + 5, 1);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no, 3);
        co(no + 4, 2);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no, 3);
        co(no + 4, 1);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no, 2);
        co(no + 4, 2);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no, 2);
        co(no + 4, 1);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no, 2);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no, 2);
        co(no + 5, 1);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no, 1);
        co(no + 3, 2);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no, 4);
        co(no + 1, 1);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no, 1);
        co(no + 3, 1);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no, 3);
        co(no + 2, 4);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no, 3);
        co(no + 2, 3);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no, 3);
        co(no + 2, 2);
      }
      if (a[no] == 1 && a[no + 1] == 0 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no, 2);
        co(no + 3, 2);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no, 1);
        co(no + 2, 4);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no, 1);
        co(no + 2, 3);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no, 1);
        co(no + 2, 2);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no, 4);
        co(no + 1, 4);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no + 1, 2);
        co(no, 5);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no, 3);
        co(no + 1, 4);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no, 1);
        co(no + 2, 1);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 0 && a[no + 3] == 1 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no, 4);
        co(no + 1, 2);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no, 1);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 0 && a[no + 5] == 1) {
        co(no, 1);
        co(no + 5, 1);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 0) {
        co(no, 1);
        co(no + 4, 2);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 0 &&
          a[no + 4] == 1 && a[no + 5] == 1) {
        co(no, 1);
        co(no + 4, 1);
      }
      if (a[no] == 1 && a[no + 1] == 1 && a[no + 2] == 1 && a[no + 3] == 1 &&
          a[no + 4] == 0 && a[no + 5] == 0) {
        co(no, 1);
        co(no + 3, 3);
      }
      no += 6;
    }
    if (n - no + 1 >= 8)
      work(no, n);
    else
      work(n - 7, n);
  }
  cout << na << endl;
  for (int i = 1; i <= na; i++)
    cout << an[i].x << ' ' << an[i].y << ' ' << an[i].z << endl;
  return 0;
}
