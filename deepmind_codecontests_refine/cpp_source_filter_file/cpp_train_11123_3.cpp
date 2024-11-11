#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    int nrlin = H / h;
    int nrcol = W / w;

    if (H % h == 0 && W % w == 0)
        cout << "No\n";
        return 0;
    }
    else
        cout << "Yes\n";

    for (int i(1); i <= H; i++)
        for (int j(1); j <= W; j++)
            cout << (i % h == 0 && j % w == 0 ? -h * w * 1000 - 1 : 1000) << " \n"[j == W];
    return 0;
}
