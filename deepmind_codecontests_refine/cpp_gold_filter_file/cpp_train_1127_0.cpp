#include <iostream>
using namespace std;
#include<string.h>
#include<set>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <cstdio>
#include <cstdlib>
#include<stack>
#include<vector>
int  a[100];
int b[100];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<a[1]<<endl;
        return 0;
    }
    int min1=1e9;
    int min2=1e9;
    b[0]=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
            b[i]=24-a[i];
        else
            b[i]=a[i];
    //cout<<b[i]<<endl;
    }
    sort(b,b+1+n);
    for(int i=1;i<=n;i++)
    {
         min1=min(min1,abs(b[i]-b[i-1]));
         //cout<<b[i]<<endl;
    }
     for(int i=1;i<=n;i++)
    {
        if(i%2==1)
            b[i]=24-a[i];
        else
            b[i]=a[i];
            //cout<<b[i]<<endl;
    }
    sort(b,b+1+n);
    for(int i=1;i<=n;i++)
    {
        min2=min(min2,abs(b[i]-b[i-1]));
    }
    cout<<min(min1,min2)<<endl;
}
