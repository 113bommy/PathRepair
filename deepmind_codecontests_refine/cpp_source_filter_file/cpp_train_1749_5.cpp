#include <bits/stdc++.h>
using namespace std;
 
int main(){
   int n,k;
   string s;
   cin>>n>>k>>s;
   ll cnt=0;
  //区切りをカウント
   for (int i = 0; i < n-1; i++)
   {
       if(s[i]!=s[i+1]) cnt++;
   }
    cout<<n-1-max(0,(cnt-2*k))<<endl;
   
   
    return 0;
}