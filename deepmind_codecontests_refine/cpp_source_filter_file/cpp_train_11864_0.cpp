//
//取り組んだ問題:平安京
//プロ怖い
//
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <list>
#define rep(i,n) for(int i = 0; i < n;i++)
#define Rep(i,n) for(int i = 0; i <= n;i++)

using namespace std;

int main(){
    int gx,gy;
    int x1,y1,x2,y2;
    int p;
    int dataset;
    cin >> dataset;
    rep(xxxxx,dataset){
        int map[20][20]={};
        int dp[20][20]={};
        dp[0][0]=1;
        cin >> gx >> gy;
        cin >> p;
        rep(xxxxxxx,p){
            cin >> x1 >> y1  >> x2 >> y2;
            if(x1 == x2){
                if(y1 > y2){
                    map[x1][y2] += 2;
                }else{
                    map[x1][y1] += 2;
                }
            }else{
                if(x1 > x2){
                    map[x2][y1] += 1;
                }else{
                    map[x1][y1] += 1;
                }
            }
        }
        for(int i = 0;i <= gx;i++){
            for(int j = 0;j <= gy;j++){
                if((map[i][j]&2) == 0)
                    dp[i][j+1] += dp[i][j];
                if(map[i][j]&1) == 0)
                    dp[i+1][j] += dp[i][j];
            }
        }
        if(dp[gx][gy]==0){
            cout << "Miserable Hokusai!" << endl;
        }else{
            cout << dp[gx][gy] << endl;
        }
    }
}