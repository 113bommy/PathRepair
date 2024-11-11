#include<cstdio>
#include<algorithm>
int main(){
    int N,K;scanf("%d%d",&N,&K);
    int x[N];
    int j;
    int ans=1<<29;
    for(int i=0;i<N;i++){
        scanf("%d",&x[i]);
    }
    for(int i=0;i+k-1<N;i++){
        ans=std::min(ans,x[i+k-1]-x[i]+std::min(abs(x[i+k-1]),abs(x[i])));
    }
    printf("%d",ans);
    return 0;
}
