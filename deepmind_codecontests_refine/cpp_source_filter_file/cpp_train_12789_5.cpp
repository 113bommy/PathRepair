#include <bits/stdc++.h>
using namespace std ;
int main()
{
    string s,c;
    cin>>s>>c;
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i];
        if(i<O.size())cout<<c[i];
    }
    return 0;
}
