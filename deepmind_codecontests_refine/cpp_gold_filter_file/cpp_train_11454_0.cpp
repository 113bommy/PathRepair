#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<cstring>
#include<queue>
#include<complex>
#include<random>
using namespace std;

typedef unsigned long long ull;

int main(){
    int N;
    ull V, x;
    cin >> N >> V;
    ull a[N], b[N], c[N], d[N];
    for (int i=0;i<N;i++) {cin >> a[i];}
    for (int i=0;i<N;i++) {cin >> b[i];}
    for (int i=0;i<N;i++) {cin >> c[i];}
    for (int i=0;i<N;i++) {cin >> d[i];}

    vector<ull> abList;
    vector<ull> cdList;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            abList.push_back(a[i]+b[j]);
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cdList.push_back(c[i]+d[j]);
        }
    }
    sort(cdList.begin(), cdList.end());

    ull S = 0;
    pair<vector<ull>::iterator, vector<ull>::iterator> p;
    for (int i=0;i<N*N;i++){
        p = equal_range(cdList.begin(), cdList.end(), V-abList[i]);
        S += (p.second -p.first);
    }

    cout << S << endl;
    return 0;
}