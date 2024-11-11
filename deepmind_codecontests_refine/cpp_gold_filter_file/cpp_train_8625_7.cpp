#include<bits/stdc++.h>
using namespace std;
string s;
int x=0,y=0,ans=0;
int main()
{
    cin>>s;
    for (int i=0;i<s.size();i++)
     if (x==y){x++; if(s[i]=='p') ans--;}
     else{y++; if(s[i]=='g') ans++;}
    printf("%d\n",ans);
    return 0;
}