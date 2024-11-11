#include <bits/stdc++.h>
using namespace std;
int a,b,c,d[3];

int main(){
  cin>>a>>b>>c;
  d[3]={a+b,b+c,c+a};
  sort(d,d+3);
  cout<<d[0]<<endl;
}
