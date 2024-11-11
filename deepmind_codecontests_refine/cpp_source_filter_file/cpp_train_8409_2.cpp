#include<bits/stdc++.h>
using namespace std;
int prime(int x){
  bool a = true;
for(int i = 2; i * i <= x; i++){
  if(x % i == 0){
a = false;
    break;
  }
}
return a;
}

int main(){
int X;
  cin >> X;
int j = 0;
  while(!prime(x+j)) j++;
cout << x + j << endl;
}