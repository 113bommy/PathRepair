#include <bits/stdc++.h>
using namespace std;
int k[7], a, b, c, x, y, z;
int main() {
  scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &x, &y, &z, &a, &b, &c, &k[1],
        &k[2], &k[3], &k[4], &k[5], &k[6]);
  if (0 <= x && x <= a) {
    if (0 <= y && y <= b) {
      if (0 <= z && z <= c) printf("0");
      if (z > c) printf("%d", k[4]);
      if (z < 0) printf("%d", k[3]);
    }
    if (y < 0) {
      if (0 <= z && z <= c) printf("%d", k[1]);
      if (z > c) printf("%d", k[4] + k[1]);
      if (z < 0) printf("%d", k[1] + k[3]);
    }
    if (y > b) {
      if (0 <= z && z <= c) printf("%d", k[2]);
      if (z > c) printf("%d", k[4] + k[2]);
      if (z < 0) printf("%d", k[3] + k[2]);
    }
  }
  if (x < 0) {
    if (0 <= y && y <= b) {
      if (0 <= z && z <= c) printf("%d", k[5]);
      if (z > c) printf("%d", k[4] + k[5]);
      if (z < 0) printf("%d", k[3] + k[5]);
    }
    if (y < 0) {
      if (0 <= z && z <= c) printf("%d", k[1] + k[5]);
      if (z > c) printf("%d", k[4] + k[1] + k[5]);
      if (z < 0) printf("%d", k[1] + k[3] + k[5]);
    }
    if (y > b) {
      if (0 <= z && z <= c) printf("%d", k[2] + k[5]);
      if (z > c) printf("%d", k[4] + k[2] + k[5]);
      if (z < 0) printf("%d", k[3] + k[2] + k[5]);
    }
  }
  if (x > a) {
    if (0 <= y && y <= b) {
      if (0 <= z && z <= c) printf("%d", k[6]);
      if (z > c) printf("%d", k[4] + k[6]);
      if (z < 0) printf("%d", k[3] + k[6]);
    }
    if (y < 0) {
      if (0 <= z && z <= c) printf("%d", k[1] + k[6]);
      if (z > c) printf("%d", k[4] + k[1] + k[6]);
      if (z < 0) printf("%d", k[1] + k[3] + k[6]);
    }
    if (y > b) {
      if (0 <= z && z <= c) printf("%d", k[2] + k[6]);
      if (z > c) printf("%d", k[4] + k[2] + k[6]);
      if (z < 0) printf("%d", k[3] + k[2] + k[6]);
    }
  }
  scanf(" ");
}
