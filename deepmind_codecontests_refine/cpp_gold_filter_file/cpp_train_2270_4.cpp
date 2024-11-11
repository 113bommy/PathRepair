#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n ,k;
    string s;
    cin>>n>>k>>s;
    s[k-1]-=('A'-'a');
    cout<<s<<endl;
}
