#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n;
int main()
{
    cin>>a>>b>>c;
    if(b>=a)
    {
        cout<<1<<endl; 
        return 0; 
    }
    if(c>=b)
    {
        cout<<-1<<endl;
        return 0;
    }
    if((a-b)%(b-c)>=1) 
    {
        n=1;
    }
    cout<<((a-b)/(b-c)+n)*2+1<<endl;
    return 0;
}