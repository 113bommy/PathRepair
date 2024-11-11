#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a,b,c,d;
  cin >> a >> b >> c;
  d = max(a,max(b,c));
  cout << a+b+c-d << endl;
}