Copy
Copy
#include <iostream>
using namespace std;
int main()
{int h,n,s=0;
cin>>h>>n;
int a[n];
 for(int i=0;i<n;i++)
 {cin>>a[i];
   s=s+a[i];
 }
   if(s>=h)
     cout<<"Yes";
 else
   cout<<"No";
 return 0;
}