#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d", (a == b ? a == c ? 1 : 2 : a == c ? 2 : b == c ? 2 : 3));
}
