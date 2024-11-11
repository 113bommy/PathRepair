#include<iostream>
#include<cstdio>

using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define REP1(i, n) for(int i=0; i<n; i++)

int INF = 10e8;
int n, m;
int dis[21][21];
int s, g, v, p;

int main(){
    cin >> n >> m;

    REP(i, n+1){
        REP(j, n+1){
            if(i!=0 && i==j){
                dis[i][j] = 0;
            } else {
                dis[i][j] = INF; dis[j][i] = INF;
            }
        }
    }

    REP(i, m){
        int a, b, c, d;
        scanf_s("%d,%d,%d,%d", &a, &b, &c, &d);
        dis[a][b] = c;
        dis[b][a] = d;
    }

    scanf_s("%d,%d,%d,%d", &s, &g, &v, &p);

    REP1(k, n+1){
        REP1(i, n+1){
            REP1(j, n+1){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int output = v - (p + dis[s][g] + dis[g][s]);
    cout << output << endl;
}