#include <bits/stdc++.h>
using namespace std;

int main(){
  	int a,b;
  cin >> a >> b;
  cout << max((max(a,b)<<1-1),a+b)) << endl;
  return 0;
}