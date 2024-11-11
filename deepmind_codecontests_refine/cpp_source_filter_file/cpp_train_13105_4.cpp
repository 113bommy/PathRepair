#include <algorithm>
#include <iostream>
#include <math.h>
#include <cstdio>
#include <string.h>
using namespace std;
int main(void){
	int h,r,ans;
	cin>>h>>r;
	if(h+r>0)ans=1;
	else if(h+w<0)ans=-1;
	else ans=0;
	cout<<ans<<endl;
	return 0;
}
