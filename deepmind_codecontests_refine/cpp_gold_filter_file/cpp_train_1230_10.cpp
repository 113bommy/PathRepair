#include<iostream>
using namespace std;
int main(){
  char a[4];
  int x=0;
  for(int i=1;i<=4;i++){
    cin>>a[i];
    if(a[i]=='+')x++;
    else x--;
  }
  cout<<x;
  return 0;
}
