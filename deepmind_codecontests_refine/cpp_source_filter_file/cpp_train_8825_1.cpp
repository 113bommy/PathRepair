#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  int i = 0;
  while (1){
  	i++;
    if(8*i/100==a && i/10==b){cout << i;break}
    if(i > 10000){cout <<-1;break;}
  }
  return 0;
} 