#include<bits/stdc++.h>
using namespace std;
int x[100010],w[100010];
int ans[100010]; 
int n,L,r,t;
long long fldl;
int main()
{
	scanf("%d%d%d",&n,&L,&t);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d",&x[i],&w[i]);
		if(w[i] == 2)w[i] = -1;
	}
    for(int i = 1;i <= n;i++)
    {
        len = x[i] + w[i] * t;
        if (len > 0) (fldl += len / L) %= n;
        else if (len < 0) (fldl += (len + 1) / L - 1) %= n;
        ans[i] = (len % L + L) % L;
    }
    sort(ans + 1 ,ans + n + 1);
    fldl = (fldl + n) % n;
    for(int i = fldl + 1;i <= n;i++)printf("%d\n",ans[i]);
    for(int i = 1;i <= fldl;i++) printf("%d\n",ans[i]);
    return 0;
}