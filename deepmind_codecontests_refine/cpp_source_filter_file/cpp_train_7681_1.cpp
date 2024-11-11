#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N = 2e5+5;
bool in[N];int a[N];
int sz=0;
set<int> st;

int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=k;i++){
		st.insert(a[i]);
		if(i<k)sz+=a[i]<a[i+1];
	}
	bool t=0;
	int ans = 0;
	if(sz!=k-1)ans++;
	else t=1;
	for(int i=2,j=k+1;j<=n;i++,j++){
		sz -= a[i-1]<a[i];sz += a[j-1]<a[j];
		int s = 0;
		if(*st.begin()==a[i-1])s++;
		st.erase(a[i-1]),st.insert(a[j]);
		if(a[j]==*st.rbegin())s++;
		if(s<2 && sz != k-1){
			ans ++ ;
		}
		if(sz==k-1) t=1;''
		// cout << i << ":" << j << ":" << ans << endl;
	}
	if(t)ans++;
	cout << ans << endl;
}