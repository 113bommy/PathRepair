#include<bits/stdc++.h>
using namespace std;
int a,n,i;
string b[105];
int main()
{
    cin>>a>>n;
    for(i=0;i<a;i++)
    {
        cin>>b[i];
    }
    sort(b,b+a);
    for(i=0;i<a;i++)
    cout<<b[i];
    cout<<endl;
}