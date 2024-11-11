#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  cout << max(a+a-1,a+b,b+b-1) <<'\n';
  return 0;
}