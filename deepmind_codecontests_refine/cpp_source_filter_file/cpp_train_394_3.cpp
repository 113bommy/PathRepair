#include<bits/stdc++.h>
main(){int n,x,a[101],A=0;std::cin>>n>>x;for(int i=0;i<n;cin>>a[i++]);std::sort(a,a+n);for(int i=0;i<n-1;i++){if(a[i]>x)break;x-=a[i];A++;}std::cout<<(x-a[n-1]?A:A+1);}