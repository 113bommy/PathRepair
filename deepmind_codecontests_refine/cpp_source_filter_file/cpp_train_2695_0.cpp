#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while(cin >> N, N)
    {
        int Y;
        int b, r, t;
        int ans;
        double ma = 0;
        cin >> Y;
        for(int i = 0; i < N; i++)
        {
            cin >> b >> r >> t;
            double latte = (t == 1) ? (1 + Y * (r / 100.0)) : pow(1 + r / 100.0));
            if(latte > ma)
            {
                ma = latte;
                ans = b;
            }
        }
        printf("%d\n", ans);
    }
}