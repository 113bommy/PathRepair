#include <bits/stdc++.h>
using namespace std;
const int maxn = 301;
int n;
int a[4], x;
double dp[maxn][maxn][maxn];

double dfs(int x, int y, int z){
    if(dp[x][y][z] > 0) return dp[x][y][z];
    if(x == 1 && y == 0 && z == 0){
        return n;
    }
    double a = x/(double)n, b = y/(double)n, c = z/(double)n;
    dp[x][y][z] = (double) n/(x+y+z) * ( (x-1 >= 0 ? a*dfs(x-1, y, z) : 0) + (y-1 >= 0 ? b*dfs(x+1, y-1, z) : 0) + (z-1 >= 0 ? c*dfs(x, y+1, z-1) : 0) + 1);
    return dp[x][y][z];
}

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x;
        a[x]++;
    }
    printf("%.20f\n", dfs(a[1], a[2], a[3]));
}
