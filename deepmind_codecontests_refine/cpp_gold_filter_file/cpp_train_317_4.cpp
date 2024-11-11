#include<iostream>
using namespace std;

int main(){
 while(1){
  int h,w;
  cin >> h >> w;
  if(h==0&&w==0) break;

  for(int i=1;i<=h;++i){
   for(int j=1;j<=w;++j){
    if((i+j)%2==0) cout << "#";
    else cout << ".";
   }
   cout << endl;
  }
  cout << endl;
 }
 return 0;
}