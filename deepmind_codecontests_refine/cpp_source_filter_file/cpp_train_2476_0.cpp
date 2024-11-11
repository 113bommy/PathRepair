#include <iostream.h> 
using namespace std;
int main()
{
	int a,b,c,d; cin>>a>>b>>c>>d;
	((b+c-1)/b) > ((a+d-1)/d) ? cout<<"No" : cout<<"Yes";
}
