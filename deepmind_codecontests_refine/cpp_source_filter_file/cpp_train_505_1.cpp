#include <cstdio>
#include <cstring>

#include <map>

#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int x, y, z, n, a, e;

int v[4];

P event[55];

 double dp[55][5050][2];

//double dp[55][5050];
int main() {

    while (scanf("%d%d%d",&x,&y,&z)) {

        if (!x&&!y&&!z) break;

        fill(event, event+55, P(0,0));

        memset(dp, 0, sizeof(dp));
        for (int i=0; i<x; i++) scanf("%d",&v[i]);

        for (int i=0; i<z; i++) {

            scanf("%d%d%d",&n,&a,&e);

            event[n]=P(a,e);
//            event[n]=P((a==1),a==3?-e:e);

        }
        dp[0][0][0]=1.0;
//        dp[0][0]=1.0;
        for (int i=0; i<y; i++) {
            if (event[i].first==1) {
                int next=min(y,i+event[i].second);
                for (int j=0; j<5050; j++) {
                    dp[next][j][1]+=dp[i][j][0];
                    for (int k=0; k<x; k++) {
                        int next2=min(y,i+v[k]);
                        dp[next2][j][0]+=dp[i][j][1]/x;
                    }
                }
            } else {
                for (int j=0; j<5050; j++) {
                    if (dp[i][j][0]==0.0&&dp[i][j][1]==0.0) continue;
                    for (int k=0; k<x; k++) {
                        int next=min(y,i+v[k]);
                        if (event[i].first==2) {
                            dp[next][j+event[i].second][0]+=dp[i][j][0]/x;
                            dp[next][j][0]+=dp[i][j][1]/x;
                        } else if (event[i].first==3) {
                            dp[next][max(0,j-event[i].second)][0]+=dp[i][j][0]/x;
                            dp[next][j][0]+=dp[i][j][1]/x;
                        } else {
                            dp[next][j][0]+=(dp[i][j][0]+dp[i][j][1])/x;
                        }
                    }
                }
            }
/*            for (int j=0; j<5050; j++) {
                if (dp[i][j]==0.0) continue;
                for (int k=0; k<x; k++) {
                    int nv=min(y,i+v[k]);
                    int np=j;
                    if (nv<y) {
                        if (event[nv].first) nv+=event[nv].second;
                        else np+=event[nv].second;
                    }
                    dp[min(y,nv)][max(0,np)]+=dp[i][j]/x;
                }
            }
        }*/
        double res=0.0;
        for (int k=0; k<5050; k++) res+=(dp[y][k][0]+dp[y][k][1])*k;
//        for (int k=0; k<5050; k++) res+=dp[y][k]*k;
//        printf("%.0f\n",res);
        printf("%d\n",(int)res);

    }

}