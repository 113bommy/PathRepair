#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  vector<int> a(10);
  while (scanf("%1d ", a) == 1) {
    for (int i = 1; i < 10; i++) {
      scanf("%1d ", &a[i]);
    }
    for (int i = 9; i >= 1; i--) {
      vector<int> b(i);
      for (int j = 0; j < i; j++) {
	b[j] = (a[j] + a[j + 1]) % 10;
      }
      a = b;
    }
    printf("%d\n", a[0]);
  }
  return 0; 
}