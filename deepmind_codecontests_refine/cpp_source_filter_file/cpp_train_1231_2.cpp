#include<iostream>
#include<algorithm>
using namespace std;
const int Maxn=1e6+300;
int a[Maxn],b[Maxn];
int n,h,cnt=0;
int main()
{
	cin>>n>>h;
	for(int i=0;i<n;i++)
	  cin>>a[i]>>b[i];
	sort(a,a+n);reverse(a,a+n);
	sort(b,b+n);reverse(b,b+n);
	for(int i=0;i<n;i++)
	  if(b[i]>a[0]&&H>0)
	  {
	  	cnt++;
	  	H-=b[i];
	  }
	while(H>0)
	{
		cnt++;
		H-=a[0];
	}
	cout<<cnt<<endl;
	return 0;
}