#include<bits/stdc++.h>
 using namespace std;
  int n,i,k,minn;
  int a[100005];
  int main()
  {
   cin>>n>>k;
   for(i=0;i<n;++i) cin>>a[i];
   sort(a,a+n);
   minn=a[k-1]-a[0];
   for(i=0;i<n-k+1;++i) minn=min(minn,a[i+k-1]-a[i]);
   cout<<minn<<endl;
   return 0;
  }