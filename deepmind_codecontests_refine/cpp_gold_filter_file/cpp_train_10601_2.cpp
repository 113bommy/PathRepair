#include<bits/stdc++.h>
using namespace std;
long long x,y;
int main()
{
    cin>>x>>y;
    cout<<floor(log2((long double)(y/x)))+1<<endl;
    return 0;
}