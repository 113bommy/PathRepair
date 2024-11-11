#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  long long int d;
  cin>>d;
  cout<<(d%2==0?a-b:b-a);
}