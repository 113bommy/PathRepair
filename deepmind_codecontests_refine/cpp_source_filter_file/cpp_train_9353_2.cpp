#include<bits/stdc++.h>

int a[100035],n,l,t,x,y;
long long cnt;

int main()
{
    scanf("%d%d%d",&n,&l,&t);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d",&x,&y);
        if (y==1){
            x += t;
            cnt += x/l;
            x %= l;
        }else{
            cnt += (x-t)/l;
            x = (x-t)%l;
            if (x < 0) cnt--, x += l;
        }
        a[i] = x;
    }
    std::sort(a+1, a+n+1);
    ((cnt%=n)+n)%=n;
    for (int i=cnt+1; i<=n; i++) printf("%d\n",a[i]);
    for (int i=1; i<=cnt; i++) printf("%d\n",a[i]);
    return 0;
}