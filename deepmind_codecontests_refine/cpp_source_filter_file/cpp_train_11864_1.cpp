#include <bits/stdc++.h>

using namespace std;

int p;
int x1[128], y1[128], x2[128], y2[128];

bool ok(int Y1, int X1, int Y2, int X2)
{
    for (int i = 0; i < p; i++){
        if (x1[i] <= X1 && X2 <= x2[i] && y1[i] <= Y1 && Y2 <= y2[i])
            return (false);
    }
    return (true);
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while (T--){
        int mp[16][16] = {0};
        int w, h;
        scanf("%d %d", &w, &h);
        
        mp[0][0] = 1;
        
        scanf("%d", &p);
        for (int i = 0; i < p; i++){
            scanf("%d %d %d %d", x1 + i, y1 + i, x2 + i, y2 + i);
            if (x1[i] > x2[i]) swap(x1[i], x2[i]);
            if (y1[i] > y2[i]) swap(y1[i], y2[i]);
        }
        
        for (int i = 0; i <= h; i++){
            for (int j = 0; j <= w; j++){
                if (i && ok(i - 1, j, i, j)) mp[i][j] += mp[i - 1][j];
                if (j && ok(i, j - 1, i, j)) mp[i][j] += mp[i][j - 1];
            }
        }
        
        if (mp[h][w] <= 0) printf("Miserable Hokusai!\n");
        else printf("%d\n", mp[h][w]);
    }
    
    return (0);
}