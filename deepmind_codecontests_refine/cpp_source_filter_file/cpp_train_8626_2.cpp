#include<iostream>
using namespace std;
bool isp[1<<17]
int n;
main()
{
    isp[0]=isp[1]=1;
    for(int i=2;i<=5e4;i++)
    {
        if(!isp[i])
        {
            for(int j=i+i;j<=5e4;j+=i)isp[j]=1;
        }
    }
    while(cin>>n,n)
    {
        int c=0;
        for(int i=2;i+2<=n;i++)if(!isp[i]&&!isp[n-i])c++;
        cout<<c<<endl;
    }
}
