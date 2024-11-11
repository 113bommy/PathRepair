#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int s=n/100;
  if(n>=s*100&&n<=s*105) cout << 1;
  else cout << 0;
}
