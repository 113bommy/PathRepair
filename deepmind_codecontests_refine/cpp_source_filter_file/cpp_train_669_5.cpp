#include <bits/stdc++.h>
using namespace std;
int n;
struct coord {
  int x, y;
} A[5], O[5];
bool operator!=(coord A, coord B) { return A.x != B.x && A.y != B.y; }
bool check1(coord A, coord B, coord C, coord D) {
  coord AB = {B.x - A.x, B.y - A.y}, CD = {D.x - C.x, D.y - C.y};
  return A != B && C != D && A.x + B.x == C.x + D.x && A.y + B.y == C.y + D.y &&
         AB.x * CD.x + AB.y * CD.y == 0 &&
         AB.x * AB.x + AB.y * AB.y == CD.x * CD.x + CD.y * CD.y;
}
bool is_square(coord A, coord B, coord C, coord D) {
  return check1(A, B, C, D) || check1(A, C, B, D) || check1(A, D, B, C);
}
bool check(int i, int j, int k, int p) {
  coord a, b, c, d;
  switch (i) {
    case 0: {
      a.x = A[1].x;
      a.y = A[1].y;
      break;
    }
    case 1: {
      a.x = -(A[1].y - O[1].y) + O[1].x;
      a.y = (A[1].x - O[1].x) + O[1].y;
      break;
    }
    case 2: {
      a.x = -(A[1].x - O[1].x) + O[1].x;
      a.y = -(A[1].y - O[1].y) + O[1].y;
      break;
    }
    case 3: {
      a.x = (A[1].y - O[1].y) + O[1].x;
      a.y = -(A[1].x - O[1].x) + O[1].y;
      break;
    }
  }
  switch (j) {
    case 0: {
      b.x = A[2].x;
      b.y = A[2].y;
      break;
    }
    case 1: {
      b.x = -(A[2].y - O[2].y) + O[2].x;
      b.y = (A[2].x - O[2].x) + O[2].y;
      break;
    }
    case 2: {
      b.x = -(A[2].x - O[2].x) + O[2].x;
      b.y = -(A[2].y - O[2].y) + O[2].y;
      break;
    }
    case 3: {
      b.x = (A[2].y - O[2].y) + O[2].x;
      b.y = -(A[2].x - O[2].x) + O[2].y;
      break;
    }
  }
  switch (k) {
    case 0: {
      c.x = A[3].x;
      c.y = A[3].y;
      break;
    }
    case 1: {
      c.x = -(A[3].y - O[3].y) + O[3].x;
      c.y = (A[3].x - O[3].x) + O[3].y;
      break;
    }
    case 2: {
      c.x = -(A[3].x - O[3].x) + O[3].x;
      c.y = -(A[3].y - O[3].y) + O[3].y;
      break;
    }
    case 3: {
      c.x = (A[3].y - O[3].y) + O[3].x;
      c.y = -(A[3].x - O[3].x) + O[3].y;
      break;
    }
  }
  switch (p) {
    case 0: {
      d.x = A[4].x;
      d.y = A[4].y;
      break;
    }
    case 1: {
      d.x = -(A[4].y - O[4].y) + O[4].x;
      d.y = (A[4].x - O[4].x) + O[4].y;
      break;
    }
    case 2: {
      d.x = -(A[4].x - O[4].x) + O[4].x;
      d.y = -(A[4].y - O[4].y) + O[4].y;
      break;
    }
    case 3: {
      d.x = (A[4].y - O[4].y) + O[4].x;
      d.y = -(A[4].x - O[4].x) + O[4].y;
      break;
    }
  }
  return is_square(a, b, c, d);
}
int main() {
  cin >> n;
  while (n--) {
    for (int i = 1; i <= 4; i++) cin >> A[i].x >> A[i].y >> O[i].x >> O[i].y;
    int mn = 100;
    for (int i = 0; i <= 3; i++)
      for (int j = 0; j <= 3; j++)
        for (int k = 0; k <= 3; k++)
          for (int p = 0; p <= 3; p++)
            if (check(i, j, k, p)) mn = min(mn, i + j + k + p);
    mn == 100 ? cout << "-1\n" : cout << mn << endl;
  }
  return 0;
}
