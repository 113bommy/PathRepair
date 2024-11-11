#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long h, w;
    cin >> h >> w;

    vector<string> m(h);
    for(auto &e: m) cin >> e;

    auto f = [&](long i) {
        return m[i/w][i%w] == '.';
    };

    vector<vector<long>> d(h*w, vector<long>(h*w, 1e9));
    for(long i=0; i<h*w; i++) {
        d[i][i] = 0;
        if(!f(i)) continue;
        if(i+w < h*w && f(i+w))
            d[i+w][i] = d[i][i+w] = 1;
        if(i-w >= 0 && f(i-w))
            d[i-w][i] = d[i][i-w] = 1;
        if((i+1)/w == i/w && f(i+1))
            d[i+1][i] = d[i][i+1] = 1;
        if(i-1 >= 0 && (i-1)/w == i/w && f(i-1))
            d[i-1][i] = d[i][i-1] = 1;
    }

    for(long k=0; k<h*w; k++)
        for(long i=0; i<h*w; i++)
            for(long j=0; j<h*w; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    long r = 0;
    for(long i=0; i<h*w; i++)
        for(long j=0; j<h*w; j++)
            if(d[i][j] < 1e9)
                r = max(r, d[i][j]);
    cout << r << endl;
}
