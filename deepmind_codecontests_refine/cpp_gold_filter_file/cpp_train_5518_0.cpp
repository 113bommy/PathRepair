 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
int N;
int P;
int X[111];
int Y[111];
int dp[111][111][111];
int cal(int x,int y){
    x--;y--;
    if(x==y)return max(Y[x]-X[x],0);

    int need=max(Y[x]-X[x],0);//?????\????????????????????£??????
    for(int i=x+1;i<=y;i++){
        int nX=max(0,X[i]-need);
        need=max(Y[i]-nX,0);

    }
    return need;
}
int main(){
    cin>>N>>P;
    REP(i,N){
        cin>>X[i]>>Y[i];
    }
    //dp????????????????????????
    REP(i,111){
        REP(j,111){
            REP(k,111){
                dp[i][j][k]=-1;
            }
        }
    }
    dp[0][0][0]=P;
    
    //dp?????´??°
    REP(i,N+1){
        if(i==0)continue;
        REP(j,N+1){
            //????????????
            REP(k,i){
                dp[i][j][i]=max(dp[i][j][i],dp[i-1][j][k]);
            }
            if(j==0)continue;
            //??????
            REP(k,N+1){               
                dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]-cal(k+1,i));
            }
            //????????????
            dp[i][j][i-1]=max(dp[i][j][i-1],dp[i-1][j-1][i-1]-cal(i,i));
        }
    }
    //
    int ans=0;
    REP(i,N+1){
        REP(j,N+1){
            REP(k,N+1){
                if(dp[i][j][k]!=-1){
                   ans=max(ans,j);
                }
            }
        }
    }
    
   /* REP(i,N+1){
        REP(j,N+1){
            REP(k,N+1){
                cout<<"dp[i]["<<j<<"]["<<k<<"]="<<dp[i][j][k] <<" "<<endl;;
            }
        }
        cout<<endl;
    }*/
    
    cout<<ans<<endl;
    return 0;
}