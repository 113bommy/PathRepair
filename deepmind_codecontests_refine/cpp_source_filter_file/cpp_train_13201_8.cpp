#include<bits/stdc++.h>
using namespace std;

int n,h,w;
int n1,n2,n3;

int main{
cin>>n>>h>>w;
for(int i=1;i<=n;i++){
int x;
cin >> x;
if(x<=h) n1++;
else if(x<=w) n2++;
else n3++;
}
cout << min(n1,min(n2,n3)) <<endl;
return 0;
}
