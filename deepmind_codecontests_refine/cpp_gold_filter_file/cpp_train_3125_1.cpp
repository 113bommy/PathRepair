#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin>>num;
    int a[num];
    int tmp=0;
    for(int i=0;i<num;i++)
        cin>>a[i];
    for(int i=0;i<num;i++)
        {for(int j=num-1;j>i;j--)
         if(a[j]<a[j-1])
          {swap(a[j],a[j-1]);
          tmp+=1;}
        }
     for(int i=0;i<num;i++) 
     if(i==num-1)cout<<a[i]<<endl;
     else cout<<a[i]<<" ";
     cout<<tmp<<endl;
    return 0;
}
