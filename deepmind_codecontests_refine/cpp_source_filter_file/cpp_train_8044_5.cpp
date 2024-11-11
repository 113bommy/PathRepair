#include <bits/stdc++.h>
using namespace std;
char ann[10][10][1000];
char c[4][3][4] = {"###", ".#.", ".#.", "..#", "###", "..#",
                   ".#.", ".#.", "###", "#..", "###", "#.."};
char M[9][10];
char an[9][10];
int n, m;
void ff() {
  int i;
  for (i = 0; i < n; i++) {
    strcpy(an[i], M[i]);
  }
}
int ans = 0;
int fang(int i, int j, int k) {
  int kk, a, b;
  if (i >= n - 2) {
    if (k > ans) {
      ans = k;
      ff();
    }
  } else if (j >= m - 2) {
    fang(i + 1, 0, k);
    return 1;
  } else {
    for (kk = 3; kk >= 0; kk--) {
      for (a = i; a < i + 3; a++) {
        for (b = j; b < j + 3; b++) {
          if ((c[kk][a - i][b - j] == '#' && M[a][b] != '.')) {
            break;
          }
        }
        if (b < j + 3) break;
      }
      if (a == i + 3) {
        for (a = i; a < i + 3; a++) {
          for (b = j; b < j + 3; b++) {
            if (c[kk][a - i][b - j] == '#') {
              M[a][b] = 'A' + k;
            }
          }
        }
        fang(i, j + 1, k + 1);
        for (a = i; a < i + 3; a++) {
          for (b = j; b < j + 3; b++) {
            if (c[kk][a - i][b - j] == '#') {
              M[a][b] = '.';
            }
          }
        }
      }
    }
    fang(i, j + 1, k);
  }
  return 1;
}
int main() {
  int j;
  strcpy(ann[7][7],
         "8\nA..BCCC\nAAAB.C.\nADBBBCE\n.DDDEEE\nFDGGGHE\nFFFG.H.\nF..GHHH\n");
  strcpy(ann[7][8],
         "9\nA..BCCC.\nAAAB.CD.\nAEBBBCD.\n.EEEFDDD\nGE.HFFFI\nGGGHFIII\nG.HHH."
         ".I\n");
  strcpy(ann[7][9],
         "10\nAAA.BC...\n.ABBBCCCD\nEA.FBCDDD\nEEEF.GGGD\nEHFFFIGJ.\n.H.IIIGJ."
         "\nHHH..IJJJ\n");
  strcpy(ann[8][7],
         "9\nA..BCCC\nAAAB.C.\nADBBBCE\n.DDDEEE\nFD.GGGE\nFFFHGI.\nFHHHGI.\n..."
         "HIII\n");
  strcpy(ann[8][8],
         "10\nAAA.BCCC\n.ABBBDC.\nEA.FBDC.\nEEEFDDDG\nEHFFFGGG\n.HIII."
         "JG\nHHHIJJJ.\n...I..J.\n");
  strcpy(ann[8][9],
         "12\nAAABBB..C\n.AD.BECCC\n.AD.BEEEC\nFDDDGEHHH\nFFFIGGGH.\nFJ.IGK."
         "HL\n.JIIIKLLL\nJJJ.KKK.L\n");
  strcpy(ann[9][7],
         "10\nA..BCCC\nAAAB.C.\nADBBBCE\n.DDDEEE\nFDGGG.E\nFFFGHHH\nFI.GJH.\n."
         "IJJJH.\nIII.J..\n");
  strcpy(ann[9][8],
         "12\nA..B.CCC\nAAAB.DC.\nAEBBBDC.\n.EEEDDDF\nGEHHHFFF\nGGGHIIIF\nGJ."
         "HKIL.\n.JKKKIL.\nJJJ.KLLL\n");
  strcpy(ann[9][9],
         "15\nAAA.BCCC.\n.ABBB.CD.\n.AE.BFCD.\nEEEFFFDDD\nG.E.HFIII\nGGGJHHHI."
         "\nGK.JHL.IM\n.KJJJLMMM\nKKK.LLL.M\n");
  scanf("%d%d", &n, &m);
  if (n >= 7 && m >= 7) {
    printf("%s", ann[n][m]);
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      M[i][j] = an[i][j] = '.';
    }
    an[i][j] = M[i][j] = 0;
  }
  fang(0, 0, 0);
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) printf("%s\n", an[i]);
  return 0;
}
