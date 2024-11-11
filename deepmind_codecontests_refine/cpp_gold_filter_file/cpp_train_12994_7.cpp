#include<iostream>
using namespace std;
int main(){
  int n;cin>>n;
  cout<<((n%111)?(n/111+1)*111:(n/111)*111)<<endl;
  return 0;
}
