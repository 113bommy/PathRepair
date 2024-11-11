#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
char s[N][3];
int a[3], n;
int main() {
    scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2]);
    for(int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    vector<char> ans;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        int ta = s[i][0] - 'A', tb = s[i][1] - 'A';
        if(a[ta] > a[tb]) {
            ans.push_back(s[i][1]);
            a[tb]++, a[ta]--;
        }else if(a[tb] > a[ta]){
            ans.push_back(s[i][0]);
            a[ta]++, a[tb]--;
        }else {
            if(a[ta] == 0) {
                flag = false;
                break;
            }
            if(i + 1 >= n || s[i][0] == s[i + 1][0] || s[i][0] == s[i + 1][1]) {
                ans.push_back(s[i][0]);
                a[ta]++, a[tb]--;
            }else {
                ans.push_back(s[i][1]);
                a[tb]++, a[ta]--;
            }
        }
    }
    if(flag) {
        printf("Yes\n");
        for(int i = 0; i < n; i++) {
            printf("%c\n", ans[i]);
        }
    }else {
        printf("No\n");
    }
    return 0;
}