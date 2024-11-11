#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){
  int a,b,c,d,result;
  cin>>a>>b>>c>>d;
  cout<<max(min(b,d)-max(a,c),0)<<endl;
}