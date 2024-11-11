#include <iostream>
using namespace std;
int main() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if((c+b-1)/b<=(a+d-1)/d||(c+b-1)/b-1==(a+d-1)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}