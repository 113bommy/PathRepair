#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;
struct node{
	double x,y;
}rec[N];
bool cmp(node a,node b){
	return atan2(a.y,a.x) < atan2(b.y,b.x);
}
int main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> rec[i].x >> rec[i].y;
	sort(rec,rec+n,cmp);
	double ans = 0;
	for(int i = 0;i < n;i++){
		double a,b;
		a = 0;
		b = 0;
		int k = i;
		do{
			a += rec[k].x;
			b += rec[k].y;
			ans = max(ans,a*a+b*b);
			k = (k+1) % n;
		}while(i != k);
	}
	cout << setprecision(15) << (long double)sqrt(ans) << endl;
	return 0;
}
