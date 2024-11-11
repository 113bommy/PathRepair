#include <iostream>

using namespace std;

int main(void){
  int a,b,c; cin>>a>>b>>c;
  cout<<(a+b==c||a==b+c||a+c==b)?"Yes":"No"<<endl;
  return 0;
}