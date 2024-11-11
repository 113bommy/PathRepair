#include <bits/stdc++.h>
using namespace std;
int n;
bool arr[600002];
int d[600002];
vector<int> flr;
vector<int> flo;
vector<int> flo2;
int oneNumber;
int minDepth, minLoc;
int cnt;
int ans;
int ansL, ansR;
void calculateMinDepth() {
  int depth = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1)
      depth--;
    else
      depth++;
    if (minDepth > depth) minDepth = depth, minLoc = i;
  }
  for (int i = 1; i <= minLoc; i++) arr[i + n] = arr[i];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char c;
    scanf(" %c", &c);
    if (c == ')') arr[i] = 1, oneNumber++;
  }
  if (n % 2 == 1 || oneNumber != n / 2) {
    printf("0\n1 1");
    return 0;
  }
  calculateMinDepth();
  int depth = 0;
  for (int i = minLoc + 1; i <= minLoc + n; i++) {
    if (arr[i])
      depth--;
    else
      depth++;
    d[i] = depth;
    if (d[i] == 0) cnt++;
  }
  if (cnt == n / 2) {
    printf("%d\n1 1", n / 2);
    return 0;
  }
  for (int i = minLoc; i <= minLoc + n; i++) {
    if (d[i] == 0) flr.push_back(i);
    if (d[i] <= 1) flo.push_back(i);
    if (i < minLoc + n && d[i] + d[i + 1] == 1) flo2.push_back(i);
  }
  ans = (int)flr.size() - 1;
  ansL = 1, ansR = 1;
  if (ans == 1) {
    ans = (int)flo.size() - 2;
    ansL = minLoc + 1, ansR = minLoc + n;
  }
  for (int i = 0; i < (int)flo.size() - 1; i++) {
    int l = flo[i], r = flo[i + 1];
    int tmpAns = (int)flr.size() - 1;
    if (r - l == 1) continue;
    for (int j = l + 1; j <= r - 1; j++) {
      if (d[j] == 2) tmpAns++;
    }
    if (ans < tmpAns) {
      ans = tmpAns, ansL = l + 1, ansR = r;
    }
  }
  for (int i = 0; i < (int)flo2.size() - 1; i++) {
    int l = flo2[i], r = flo2[++i] + 1;
    int tmpAns = 0;
    for (int j = l + 1; j <= r - 1; j++) {
      if (d[j] == 1) tmpAns++;
    }
    if (ans < tmpAns) {
      ans = tmpAns, ansL = l + 1, ansR = r;
    }
  }
  printf("%d\n%d %d", ans, ansL > n ? ansL - n : ansL,
         ansR > n ? ansR - n : ansR);
}
