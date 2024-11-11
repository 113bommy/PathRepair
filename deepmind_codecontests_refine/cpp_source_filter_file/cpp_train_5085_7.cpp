#include <bits/stdc++.h>
using namespace std;
int a,b,c;

int main(){
  cin>>a>>b>>c;
  a[3]={a+b,b+c,c+a};
  sort(a,a+3);
  cout<<a[0]<<endl;
}
