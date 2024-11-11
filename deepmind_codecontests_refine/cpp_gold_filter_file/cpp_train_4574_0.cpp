#include <iostream>
#include <cstring>
#include<cstdio>
using namespace std;
long long int c(long long m,long long n)
{
    long long ans=1;
    for(long long k=1; k<=n; k++)
    {
        ans=(ans*(m-n+k))/k;
    }
    return ans;
}
int main()
{
    long long  l, k;
    while(cin >> l >> k)
    {
        long long  i, j;
        long long sum = 0;
        for( i=1; i<=(l+1)/2; i++)
        {
            sum++;
            for( j=1; j<=i; j++ )
            {
                if( i-j+k*j + i-1 > l) break;
                sum += c(i,j);
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
