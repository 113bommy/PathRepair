#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  string ans="Three";
  char a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)
    if(a[i]=="Y")ans="Four";
  cout<<ans<<endl;
  return 0;
}
