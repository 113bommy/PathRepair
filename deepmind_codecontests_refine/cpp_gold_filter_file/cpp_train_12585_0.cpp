#include <bits/stdc++.h>
using namespace std;
int main()
{
    int W, H, N;
    int ymax[100005] = {};

    cin >> W >> H >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ymax[x] = max(ymax[x], y);
    }
    
    int minv = 1 << 28;
    int mm = 0;
    for(int i = W - 1; i >= 0; i--) {
        minv = min(i + mm, minv);
        mm = max(ymax[i], mm);
    }

    cout << minv << endl;
    return (0);
}