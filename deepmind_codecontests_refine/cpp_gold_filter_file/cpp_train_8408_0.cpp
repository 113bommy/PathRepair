#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int a,b,x;
  cin>>x;
  for(int i=-120;i<120;i++){
    for(int j=-120;j<120;j++){
      if(pow(i,5)-pow(j,5)==x){
        a=i;
        b=j;
        break;
      }
  	}
  }
  cout<<a<<' '<<b<<endl;
}