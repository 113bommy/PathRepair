#include<bits/stdc++.h>
using namespace std;
int main()
{int n,s=0;
 int a[200];
 cin>>n;
 for(int i=0;i<2*n;i++)
    cin>>a[i];
 sort(a,a+2*n);
 for(int i=0;i<2*n;i+=2)
    s+=a[i];
 cout<<s<<endl;
}