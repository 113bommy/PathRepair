#include <bits/stdc++.h>
using namespace std;
long long a,b,c,y;
int main()
{
    cin>>a>>b>>c;
    if(b>=a)
    {
        cout<<1<<endl;
        exit(0);
    }
    if(c>=b)
    {
        cout<<-1<<endl;
        return 0;
    }
    if((a-b)%(b-c)>=1)y=1;
    cout<<((a-b)/(b-c)+y)*2+1<<endl;
}