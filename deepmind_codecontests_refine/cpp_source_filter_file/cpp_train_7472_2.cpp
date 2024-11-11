#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
char s[N];
vector<pair<int, int>> pa, pb;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        int a = 0, b = 0;
        for(int j = 0; s[j]; j++) {
            if(s[j] == '(') a++;
            else if(a) a--;
            else b++;
        }
        if(a <= b) pa.push_back({a, b});
        else pb.push_back({a, b}); 
    }
    sort(pa.begin(), pa.end());
    sort(pb.begin(), pb.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    int sum = 0;
    bool flag = true;
    for(int i = 0; i < pa.size(); i++) {
        sum -= pa[i].first;
        if(sum < 0) flag = false;
        sum += pa[i].second;
    }
    for(int i = 0; i < pb.size(); i++) {
        sum -= pb[i].first;
        if(sum < 0) flag = false;
        sum += pb[i].second;
    }
    if(sum) flag = false;
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}

F.cpp