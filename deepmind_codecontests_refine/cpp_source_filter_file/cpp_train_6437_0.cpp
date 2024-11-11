#include <bits/stdc++.h>
using namespace std;
string a;
int ans=1<<30; 
int main()
{
    cin>>a;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]!=a[i-1])
            ans=min(ans,max(i,int(a.size())-i)); 
    }      
    cout<<min(ans,int(s.size()))<<endl; 
    return 0;
}