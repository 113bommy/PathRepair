#include <bits/stdc++.h>
using namespace std;
int P[100010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &P[i]);
  int r1 = -1, r2 = -1, r3 = -1;
  int ind1 = -1, ind2 = -1, ind3 = -1;
  for (int i = 0; i < n;) {
    r1 = -1, r2 = -1, r3 = -1;
    ind1 = -1, ind2 = -1, ind3 = -1;
    int j;
    for (j = i; j < n; j++) {
      if (P[j] == 0) break;
      if (P[j] > r1) {
        r3 = r2;
        ind3 = ind2;
        r2 = r1;
        ind2 = ind1;
        r1 = P[j];
        ind1 = j;
      } else if (P[j] > r2) {
        r3 = r2;
        ind3 = ind2;
        r2 = P[j];
        ind2 = j;
      } else if (P[j] > r3) {
        r3 = P[j];
        ind3 = j;
      }
    }
    int k;
    int broj = 1;
    int bioq = 0, biof = 0, bios = 0;
    for (k = i; k <= j && k < n; k++) {
      if (P[k] == 0) {
        printf("%d", bioq + biof + bios);
        broj = bioq + biof + bios;
        if (broj) printf(" ");
        if (bios) {
          broj--;
          printf("popStack");
          if (broj) printf(" ");
        }
        if (bioq) {
          broj--;
          printf("popQueue");
          if (broj) printf(" ");
        }
        if (biof) {
          broj--;
          printf("popFront");
        }
        if (k != n - 1) printf("\n");
        break;
      } else if (k == ind1 || k == ind2 || k == ind3) {
        if (broj == 1) {
          bioq = 1;
          printf("pushQueue");
        }
        if (broj == 2) {
          biof = 1;
          printf("pushFront");
        }
        if (broj == 3) {
          bios = 1;
          printf("pushStack");
        }
        broj++;
      } else if (broj < 3) {
        bios = 1;
        printf("pushStack");
      } else {
        bioq = 1;
        printf("pushQueue");
      }
      if (k != n - 1) printf("\n");
    }
    i = k + 1;
  }
  return 0;
}
