#include<iostream>
using namespace std;
int main(){
  int x,y;
  cin>>x>>y;
  if(x>9||y>9)
    cout<<-1;
  else
    cout<<x*y;
}