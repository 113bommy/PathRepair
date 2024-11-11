#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	unsigned long n,c5;

	while(1){
		cin>>n; if(n==0) return 0;
		c5=0;
		for(unsigned long i=1;i<=n;i++){
			unsigned long j=i;

			while(j%5==0){c5++;j/=5;}
		}
		cout<<c5<<endl;
	}
}