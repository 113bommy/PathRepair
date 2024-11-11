#include <bits/stdc++.h>
using namespace std;
int x[5], y[5];
char ans[105][105];
int b[5];
int main() {
  for (int i = 0; i < 3; i++) scanf("%d%d", &x[i], &y[i]);
  int len = 0;
  int shu = 3, px = 0, py = 0;
  for (int i = 0; i < 3; i++) len = max(len, max(x[i], y[i]));
  for (int ii = 0; ii < 3; ii++) {
    if (x[ii] == len || y[ii] == len) {
      shu--;
      b[ii] = 1;
      if (x[ii] == len) {
        for (int i = px; i < px + y[ii]; i++)
          for (int j = 0; j < x[ii]; j++) ans[i][j] = 'A' + ii;
        px += y[ii];
      } else if (y[ii] == len) {
        for (int i = px; i < px + x[ii]; i++)
          for (int j = 0; j < y[ii]; j++) ans[i][j] = 'A' + ii;
        px += x[ii];
      }
    }
  }
  px = len - px;
  if (shu == 0) {
    if (px != len) {
      cout << "-1\n";
      return 0;
    }
    cout << len << endl;
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) printf("%c", ans[i][j]);
      printf("\n");
    }
  } else if (shu == 1)
    printf("-1\n");
  else if (shu == 2) {
    int pd = 1;
    int x1, x2, y1, y2;
    int bb1, bb2;
    for (int i = 0; i < 3; i++) {
      if (b[i] == 0 && pd) {
        x1 = x[i];
        y1 = y[i];
        bb1 = i;
        pd = 0;
      } else if (b[i] == 0 && pd == 0) {
        x2 = x[i];
        y2 = y[i];
        bb2 = i;
      }
    }
    if (x1 == px && x2 == px) {
      if (y1 + y2 != len) {
        cout << "-1\n";
        return 0;
      }
      for (int i = len - px; i < len; i++)
        for (int j = 0; j < len; j++)
          if (j < y1)
            ans[i][j] = 'A' + bb1;
          else
            ans[i][j] = 'A' + bb2;
      cout << len << endl;
      for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) printf("%c", ans[i][j]);
        printf("\n");
      }
    } else if (x1 == px && y2 == px) {
      if (y1 + x2 != len) {
        cout << "-1\n";
        return 0;
      }
      cout << len << endl;
      for (int i = len - px; i < len; i++)
        for (int j = 0; j < len; j++)
          if (j < y1)
            ans[i][j] = 'A' + bb1;
          else
            ans[i][j] = 'A' + bb2;
      for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) printf("%c", ans[i][j]);
        printf("\n");
      }
    } else if (y1 == px && x2 == px) {
      if (x1 + y2 != len) {
        cout << "-1\n";
        return 0;
      }
      cout << len << endl;
      for (int i = len - px; i < len; i++)
        for (int j = 0; j < len; j++)
          if (j < x1)
            ans[i][j] = 'A' + bb1;
          else
            ans[i][j] = 'A' + bb2;
      for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) printf("%c", ans[i][j]);
        printf("\n");
      }
    } else if (y1 == px && y2 == px) {
      if (x1 + x2 != len) {
        cout << "-1\n";
        return 0;
      }
      cout << len << endl;
      for (int i = len - px; i < len; i++)
        for (int j = 0; j < len; j++)
          if (j < x1)
            ans[i][j] = 'A' + bb1;
          else
            ans[i][j] = 'A' + bb2;
      for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) printf("%c", ans[i][j]);
        printf("\n");
      }
    } else
      cout << "-1\n";
  }
  return 0;
}
