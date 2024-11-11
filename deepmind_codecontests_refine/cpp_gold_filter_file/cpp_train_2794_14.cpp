#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,x;
  cin >> x >> a >> b;
  if(abs(a-x)<abs(b-x)) cout << 'A';
  else cout << 'B';
return 0;}