#include<iostream>
using namespace std;

int main(){
  string a;
  cin>>a;
  ((a[0]==a[1]&&a[1]==a[2])||(a[1]==a[2]&&a[2]==a[3]))cout<<"Yes":cout<<"No";
  return 0;
}
