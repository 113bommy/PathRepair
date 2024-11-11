#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

int n,m,k,i,j,a[110],num1,num2,num3;
bool p;
char ch,;

int main()
{
    cin>>n>>m;
    for (i=0;i<n;i++)
    for (j=0;j<m;j++) {cin>>ch;a[ch-'a']++;}
    for (i=0;i<26;i++) 
    {
        if (a[i]>=4)
        {
          num1+=a[i]/4;
          a[i]=a[i]%4;
        }
        if (a[i]>=2)
        {
            num2+=a[i]/2;
            a[i]=a[i]%2;
        }
        if (a[i]==1)
            num3++;
    }
    if ((num3>1)||(num1<(n/2)*(m/2))||(num2+2*(num1-(n/2)*(m/2))<(
    (n*m-(n/2)*(m/2)*4)/2))) {cout<<"No";return 0;}
    cout<<"Yes";
    return 0;
}
