#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin >> N;vector<int> a(N);
    for(int i =0;i< N;i++) cin >> a[i];
    int S = a[0];
    for(int i = 1;i <N;i++) S ^=a[i];
    if (S == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}