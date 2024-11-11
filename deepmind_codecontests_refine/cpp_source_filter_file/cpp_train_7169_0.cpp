#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n;
  cin >> n;
  while(n--){
    double x[4],y[4];
    for(int i=0;i<4;i++) cin >> x[i] >> y[i]; 
    if(abs((x[3]-x[2])*(y[1]-y[0])-(x[1]-x[0])*(y[3]-y[2])) < 1e-10){
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}