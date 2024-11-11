#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, i=3;
  cin >>a >>b >>c ;

  if(a==b) i--;
  if(a==c) i--;
  else if(b==c)i--;
   cout << i << endl;
}
