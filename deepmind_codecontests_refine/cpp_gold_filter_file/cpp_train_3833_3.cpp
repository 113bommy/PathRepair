#include <iostream>
using namespace std;
int main()
{	
  	int a,b,c;
    cin>>a>>b>>c;
  	cout<<(b + (min(a + b + 1,c)))<<endl;
	return 0;
}
