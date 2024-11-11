#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

class Data
{
public:
    int w, s;
    string name;
    bool operator<(const Data& d) const{
        return s < d.s;
    }
};

int n;
vector<Data> d;
vector<bool> used;
vector<int> bestIndex;
int bestG;

void solve(int k, vector<int>& index, int g, int sumW)
{
    if(k == n){
        if(g < bestG){
            bestG = g;
            bestIndex = index;
        }
        return;
    }

    for(int i=0; i<n; ++i){
        if(used[i])
            continue;
        if(d[i].s >= sumW){
            used[i] = true;
            index[k] = i;
            solve(k+1, index, g+(n-k)*d[i].w, sumW+d[i].w);
            used[i] = false;
        }else{
            return;
        }
    }
}

int main()
{
    for(;;){
        cin >> n;
        if(n == 0)
            return 0;

        d.resize(n);
        for(int i=0; i<n; ++i)
            cin >> d[i].name >> d[i].w >> d[i].s;
        sort(d.begin(), d.end());

        bestG = INT_MAX;
        used.assign(n, false);
        vector<int> index(n);
        solve(0, index, 0, 0);
        for(int i=n-1; i>=0; --i)
            cout << d[bestIndex[i]].name << endl;
    }
}