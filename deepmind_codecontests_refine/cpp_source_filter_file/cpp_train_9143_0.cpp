#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
    int main()
    {
    	
       scanf("%d %d %d %d",&a,&b,&c,&d);
  

	cout<<max(0,min(b,d)-max(a,c))<<endl;