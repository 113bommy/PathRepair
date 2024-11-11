#include <iostream>
using namespace std;
int main()
{
char a[3];
int b=700;
cin>>a;
for(int i=0;i<3;i++)
{
	if(a[i]=='o')
	b+=100;
}
cout<<b<<endl;
return 0;
}