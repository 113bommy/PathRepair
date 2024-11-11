#include <cstdio>

using namespace std;

int main()
{
  int x, y, r, hisi = 0, tyou = 0;
  while (scanf("%d,%d,%d ", &x, &y, &r) == 3) {
    if (x == y) {hisi++;}
    if (x * x + y * y == r * r) {tyou++;}
  }
  
  printf("%d\n%d\n", tyou, hisi);
}