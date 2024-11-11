#include <iostream>

using namespace std;
 
int main()
{
	int q,w;
	cin>>q>>w;
	cout<<max(q+w,max(q+q-1,w+w-1));
}