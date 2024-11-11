#include <bits/stdc++>
using namespace std;
int main(){
	long long w,h,x,y;
	cin>>w>>h>>x>>y;
	cout<<fixed<<setprecision(12)<<w*h/2.0<<" "<<(w==x*2&&h==y*2?1:0)<<endl;
	return 0;
}