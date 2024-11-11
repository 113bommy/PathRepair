#include<iostream>
#include<algorithm >
using namespace std;
int main(){
int a,b,c;
  cin>>a>>b>>c;
  int n = max({a,b,c});
  cout<<a+b+c+n*9<<endl;
}
