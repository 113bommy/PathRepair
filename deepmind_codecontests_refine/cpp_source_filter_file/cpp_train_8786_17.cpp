#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int x, y, n;
  scanf("%d", &n);
  vector<int> a(n);
  int students = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    students += a[i];
  }
  scanf("%d%d", &x, &y);
  int count = 0;
  for (int points = 0; points < a.size(); ++points) {
    count += a[points];
    if (count > x && count < y && students - count > x &&
        students - count < y) {
      printf("%d\n", points + 2);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
