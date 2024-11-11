#include<iostream>
using namespace std;
int main(){
  int a,b,c,d;cin>>a>>b>>c>>d;
  int x=(a+d-1)/d;
  int y=(c+b-1)/b;
  cout << (y<=x?"Yes":"No") << endl;
  return 0;
}  
