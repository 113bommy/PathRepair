#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000001
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
    int n,h;
    cin >> n >> h;
    char x[105][25];
    int t[105];
    int len[105];
    for(int i=0;i<n;i++)
    {
        scanf("%s%d",x[i],&t[i]);
        len[i] = strlen(x[i]);
    }
    int ok=0,sum=0;
    for(int i=0;i<n;i++)
    {
        int nx = 0,miss = 0;
        while(1)
        {
            printf("? %s\n", x[i]);
            fflush(stdout);
            char c[2];
            scanf("%s", c);
            int q,w;
            if(x[i][nx] >= 'a' && x[i][nx] <= 'z') q = x[i][nx]-'a';
            else q = x[i][nx]-'A';
            if(c[0] >= 'a' && c[0] <= 'z') w = c[0]-'a';
            else w = c[0]-'A';
            sum++;
            if(q == w)
            {
                x[i][nx] = '_'; nx++; ok++;
                if(nx == len[i]) break;
            }
            else
            {
                miss++;
                if(miss > t[i])
                {
                    h--;
                    if(h == 0)
                    {
                        printf("! Game Over\n"); fflush(stdout); return 0;
                    }
                    break;
                }
            }
        }
    }
    double xx = (double)ok/(double)sum*1000;
    int s = floor(xx);
    printf("! Game Clear %.1lf\n", (double)s/10.0); fflush(stdout); return 0;
}