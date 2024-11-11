#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void) {
  int a[4], i;
  for(i = 0; i < 4; ++i)scanf("%d", &a[i]);
  sort(a, a + 4);
  if(a[0] == a[1] && a[2] == a[3]) printf("yes\n");
  else printf("no\n");
  return 0;
}
