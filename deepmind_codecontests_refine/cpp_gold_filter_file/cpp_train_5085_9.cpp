#include <bits/stdc++.h>
using namespace std;
int a,b,c;

int main(){
  cin>>a>>b>>c;
  int d[3]={a+b,b+c,c+a};
  sort(d,d+3);
  cout<<d[0]<<endl;
}
