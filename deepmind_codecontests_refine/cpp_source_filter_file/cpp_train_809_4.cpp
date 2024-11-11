#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,ans;
int ans[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]); ans^=a[i];
	}
	if (ans==0) puts("Yes"); else puts("No");
}