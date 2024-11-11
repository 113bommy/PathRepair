#include<ibts/stdc++.h>
using namespace std;
char a[3];
int ans;
int main()
{
cin>>a;
for(int i=0;i<=3;i++){
if(a[i]=='+')ans++;
if(a[i]=='-')ans--;}
cout<<ans<<endl;
return 0;
}