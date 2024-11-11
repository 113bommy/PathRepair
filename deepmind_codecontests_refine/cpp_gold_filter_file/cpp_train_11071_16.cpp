#include <bits/stdc++.h>
bool inters(long ra, long rb, long dr) {
  return dr > (ra - rb) * (ra - rb) && dr < (ra + rb) * (ra + rb);
}
bool lay(long ra, long Ra, long rb, long dr) {
  return ra < rb && rb < Ra && dr <= (rb - ra) * (rb - ra) &&
         dr <= (Ra - rb) * (Ra - rb);
}
bool flay(long ra, long Ra, long rb, long dr) {
  return 2 * rb <= (Ra - ra) && dr >= (rb + ra) * (rb + ra) &&
         dr <= (Ra - rb) * (Ra - rb);
}
int main() {
  long x1, y1, r1, R1, x2, y2, r2, R2;
  scanf("%d %d %d %d", &x1, &y1, &r1, &R1);
  scanf("%d %d %d %d", &x2, &y2, &r2, &R2);
  long dR = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  long Count = 0;
  int pc[4] = {1, 1, 1, 1};
  if (inters(r1, r2, dR)) {
    pc[0] = 0;
    pc[2] = 0;
  };
  if (inters(r1, R2, dR)) {
    pc[0] = 0;
    pc[3] = 0;
  };
  if (inters(R1, r2, dR)) {
    pc[1] = 0;
    pc[2] = 0;
  };
  if (inters(R1, R2, dR)) {
    pc[1] = 0;
    pc[3] = 0;
  };
  if (lay(r2, R2, r1, dR)) pc[0] = 0;
  if (lay(r2, R2, R1, dR)) pc[1] = 0;
  if (lay(r1, R1, r2, dR)) pc[2] = 0;
  if (lay(r1, R1, R2, dR)) pc[3] = 0;
  if (flay(r2, R2, r1, dR)) pc[0] = 0;
  if (flay(r2, R2, R1, dR)) pc[1] = 0;
  if (flay(r1, R1, r2, dR)) pc[2] = 0;
  if (flay(r1, R1, R2, dR)) pc[3] = 0;
  for (int k = 0; k < 4; k++) Count += pc[k];
  printf("%d", Count);
  return 0;
}
