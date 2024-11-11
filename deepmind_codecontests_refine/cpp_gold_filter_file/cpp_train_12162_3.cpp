#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int x=max(a,max(b,c));
  cout << x*10+a+b+c-x << endl;
}
