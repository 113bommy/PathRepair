#include <iostream>
#include <cmath>
using namespace std;
int main () 
{
int n;
cin>>n;
int a[102];
long long sum=0;
for (int i=1;i<=n;i++){
	cin>>a[i];
	sum+=a[i];
}
long long j=round(double(sum)/n);
int o=0;
for (int i=1;i<=n;i++){
	o+=(a[i]-j)*(a[i]-j);
}
cout<<o;
