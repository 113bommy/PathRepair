#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a,b;
    cin>>n>>a>>b;
    if((b-a)%2==0)
        cout<<(b-a)/2<<endl;
    else
      cout<<min((a+(((b-a)-1)/2)),((n-b+1)+(b-a-1)/2)<<endl;
    return 0;
}
