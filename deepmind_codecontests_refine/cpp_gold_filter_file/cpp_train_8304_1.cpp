#include<bits/stdc++.h>
using namespace std;
int main(){
  double h,n,a;
  cin>>h>>n;
  a=0;
  for(int i=0;i<n;i++){
    cin >> a;
    h-=a;
  }
  puts(h<=0? "Yes":"No");
}
