#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
int N;
vector<int> pts;
char str[limN];
int main() {
  bool funca = true;
  int w;
  scanf("%s", str);
  N = strlen(str);
  for (int i = 0; i < N; i++)
    if (str[i] == '.') pts.push_back(i);
  w = pts.size();
  if (w) {
    funca &= pts[0] <= 8;
    funca &= pts[0] > 0;
    funca &= N - pts[w - 1] <= 4;
    funca &= pts[w - 1] + 1 < N;
  } else
    funca = false;
  for (int i = 1; i < w; i++) {
    funca &= (pts[i] - pts[i - 1] <= 12 && pts[i] - pts[i - 1] >= 3);
  }
  if (!funca) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  for (int i = 0; i < pts[0]; i++) printf("%c", str[i]);
  for (int i = 1; i < w; i++) {
    printf(".");
    int d = pts[i] - pts[i - 1] - 1;
    if (d <= 4) {
      printf("%c\n", str[pts[i - 1] + 1]);
      for (int j = pts[i - 1] + 2; j < pts[i]; j++) printf("%c", str[j]);
    } else {
      for (int j = pts[i - 1] + 1; j <= pts[i - 1] + 3; j++)
        printf("%c", str[j]);
      printf("\n");
      for (int j = pts[i - 1] + 4; j < pts[i]; j++) printf("%c", str[j]);
    }
  }
  for (int i = pts[w - 1]; i < N; i++) printf("%c", str[i]);
  printf("\n");
}
