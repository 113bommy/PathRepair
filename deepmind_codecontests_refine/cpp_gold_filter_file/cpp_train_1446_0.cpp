#include<cstdio>
using namespace std;
int m[100],a[100],b[100],n;
bool judge(int x){
    int w=0;
    for(int i=0;i<n;i++)
        if(a[i]<=x&&b[i]>x)w+=m[i];
    return w<=150;
}
int main(){
    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++)scanf("%d%d%d",m+i,a+i,b+i);
        bool res=true;
        for(int i=0;i<n;i++)res&=judge(a[i]);
        for(int i=0;i<n;i++)res&=judge(b[i]);
        puts(res?"OK":"NG");
    }
    return 0;
}