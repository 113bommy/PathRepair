#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  cout<<min(min(a+b,a-b),a*b)<<endl;
