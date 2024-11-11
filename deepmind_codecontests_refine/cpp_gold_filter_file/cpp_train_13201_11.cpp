#include <bits/stdc++.h>
using namespace std;
int main(){
 int n,a,b;
  cin>>n>>a>>b;
  int c1=0,c2=0,c3=0;
  int x;
  for(int i=0;i<n;i++){
    cin>>x;
    if(x<=a)
      c1++;
    else if(x<=b)
      c2++;
    else
      c3++;
  }
  cout<<min(c1,min(c2,c3))<<endl;
  return 0;
}
