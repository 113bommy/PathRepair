å#include <cstdio>
#define S 5010
using namespace std;
int l[S][S]={0};

int main(){
    int N,M,a,b,x,i,j;
    scanf("%d %d",&N,&M);
    for(i=0;i<M;i++){
        scanf("%d %d %d",&a,&b,&x);
        l[a][b]++;
        l[a][b+1]--;
        l[a+x+1][b]--;
        l[a+x+2][b+1]++;
        l[a+x+2][b+x+2]--;
        l[a+x+1][b+x+2]++;
    }
    for(i=1;i<N+4;i++){
        for(j=1;j<N+4;j++){
            l[i][j]+=l[i][j-1];
        }
    }
    for(j=1;j<N+4;j++){
        for(i=1;i<N+4;i++){
            l[i][j]+=l[i-1][j]; 
        }
    }
    for(i=1;i<N+4;i++){
        for(j=1;j<N+4;j++){
            if(i+j-1<S){
                l[i+j-1][j]+=l[i+j-2][j-1]; 
            }
        }
    }
    int cnt=0;
    for(i=0;i<N+4;i++){
        for(j=0;j<N+4;j++){
            if(l[i][j]>0){cnt++;}
        }
    }
    printf("%d\n",cnt);
    return 0;
}
    

