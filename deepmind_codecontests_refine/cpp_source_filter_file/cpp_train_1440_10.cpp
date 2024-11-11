#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x,sum=0,minnum=1000;
  cin>>n>>x;
  vector<int> num(n);
  for(int &a:num){
    cin>>a;
    sum+=a;
    minnum = min(minnum,a);
  }
  x-=sum;
  cout>>n+x/minnum<<endl;
}