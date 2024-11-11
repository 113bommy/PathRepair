clude<bits/stdc++.h>
using namespace std;
int main()  
{
  int n;
  cin>>n;
  int ans=0;
  for(int i=1;i<=9;i++){
  	if(n%i==0&&(n/i)<=9) ans=1;
  }
  if(ans) puts("Yes");
  else puts("No");
}