#include <bits/stdc++.h>
using namespace std;
long long dotProduct(long long x, long long y, long long u, long long v) {
  return (x * u + y * v);
}
long long crossProduct(long long x, long long y, long long u, long long v) {
  return ((x * v) - (y * u));
}
struct ray {
  long long x[2];
  long long y[2];
};
bool checkLength(long long x, long long y, long long w0, long long z0) {
  if ((x < 0 && w0 > 0) || (x > 0 && w0 < 0)) {
    return false;
  }
  if ((y < 0 && z0 > 0) || (y > 0 && z0 < 0)) {
    return false;
  }
  long long l = x * x + y * y;
  long long lprime = w0 * w0 + z0 * z0;
  if (lprime >= l) {
    return false;
  }
  if (l >= 4 * lprime) {
    return (16 * lprime >= l);
  } else {
    return (16 * l >= 25 * lprime);
  }
}
ray lines[3];
ray atop[2];
ray across;
int main() {
  long long n, x, y, u, v, w0, z0, w1, z1, headx, heady, lng;
  bool point, head, isV, goodA;
  cin >> n;
  while (n > 0) {
    point = false;
    head = false;
    isV = false;
    goodA = false;
    for (int i = 0; i < 3; i++) {
      cin >> lines[i].x[0] >> lines[i].y[0] >> lines[i].x[1] >> lines[i].y[1];
      if (lines[i].x[0] == lines[i].x[1] && lines[i].y[0] == lines[i].y[1]) {
        point = true;
      }
    }
    if (!point) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          headx = lines[i].x[j];
          heady = lines[i].y[j];
          for (int k = i + 1; k < 3; k++) {
            for (int l = 0; l < 2; l++) {
              if (headx == lines[k].x[l] && heady == lines[k].y[l] && !head) {
                head = true;
                if (j % 2 == 0) {
                  atop[0].x[0] = lines[i].x[j];
                  atop[0].x[1] = lines[i].x[j + 1];
                  atop[0].y[0] = lines[i].y[j];
                  atop[0].y[1] = lines[i].y[j + 1];
                } else if (j % 2 == 1) {
                  atop[0].x[0] = lines[i].x[j];
                  atop[0].x[1] = lines[i].x[j - 1];
                  atop[0].y[0] = lines[i].y[j];
                  atop[0].y[1] = lines[i].y[j - 1];
                }
                if (l % 2 == 0) {
                  atop[1].x[0] = lines[k].x[l];
                  atop[1].x[1] = lines[k].x[l + 1];
                  atop[1].y[0] = lines[k].y[l];
                  atop[1].y[1] = lines[k].y[l + 1];
                } else if (l % 2 == 1) {
                  atop[1].x[0] = lines[k].x[l];
                  atop[1].x[1] = lines[k].x[l - 1];
                  atop[1].y[0] = lines[k].y[l];
                  atop[1].y[1] = lines[k].y[l - 1];
                }
                if (i == 0) {
                  if (k == 1) {
                    across = lines[2];
                  } else {
                    across = lines[1];
                  }
                } else {
                  across = lines[0];
                }
              } else if (headx == lines[k].x[l] && heady == lines[k].y[l] &&
                         head) {
                head = false;
                i = j = k = l = 99;
              }
            }
          }
        }
      }
    }
    if (head) {
      x = atop[0].x[1] - atop[0].x[0];
      y = atop[0].y[1] - atop[0].y[0];
      u = atop[1].x[1] - atop[1].x[0];
      v = atop[1].y[1] - atop[1].y[0];
      if (dotProduct(x, y, u, v) >= 0) {
        isV = true;
      }
    }
    if (isV) {
      w0 = across.x[0] - atop[0].x[0];
      z0 = across.y[0] - atop[0].y[0];
      w1 = across.x[1] - atop[0].x[0];
      z1 = across.y[1] - atop[0].y[0];
      if (crossProduct(x, y, w0, z0) == 0 && crossProduct(u, v, w1, z1) == 0) {
        goodA = checkLength(x, y, w0, z0);
        if (goodA) {
          goodA = checkLength(u, v, w1, z1);
        }
      } else if (crossProduct(x, y, w1, z1) == 0 &&
                 crossProduct(u, v, w0, z0) == 0) {
        goodA = checkLength(x, y, w1, z1);
        if (goodA) {
          goodA = checkLength(u, v, w0, z0);
        }
      }
    }
    if (goodA) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    n--;
  }
  return 0;
}
