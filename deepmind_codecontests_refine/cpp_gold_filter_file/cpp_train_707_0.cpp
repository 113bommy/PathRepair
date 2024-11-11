#include <bits/stdc++.h>
using namespace std;
double s(long long n)
{
    long long x=n,y=0;
    
    while (x)
    {
        y+=x%10;
        x/=10;
    }
    return (double)n/y;
}
int main()
{
    long long K;
    long long n=1;
    long long x=1;
    cin>>K;
    for (int i = 0; i < K; i++)
    {
        cout<<n<<endl;
        if (s(n+x)>s(n+x*10))
            x*=10;
        n+=x;
    }
    return 0;
}
