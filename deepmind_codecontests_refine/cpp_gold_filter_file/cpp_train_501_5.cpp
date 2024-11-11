#include<iostream>
using namespace std;
int main(){
int a, b, i, Mma=-1, min=1001;
  cin >> a;
  for(i=0;i<a;i++) {
  cin >> b;
  if(min>b) min=b;
    if(Mma<b) Mma=b;
  }
cout << Mma-min <<endl;
}