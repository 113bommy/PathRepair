#include<cstdio>

using namespace std;

long long a[100100];
int N;
int req[100100];
bool must[100100];

int calc(int x){
    long long tmp = 1;
    for(int i = 0; i < x; ++i){
        if(tmp >= x) return i;
        tmp *= 2;
    }
    return -1;
}

int solve(){
    for(int i = 0; i < N; ++i){
        req[i] = calc(a[i]);
        int tmp = a[i] & (a[i] - 1);
        if(tmp == 0) must[i] = false;
        else must[i] = true;
    }
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < N; ++i){
        if(cur < req[i]){
            ans += (req[i] - cur);
            cur = req[i];
        }else if(cur == req[i]){
            if(must[i]){
                cur = req[i] - 1;
            }
        }else{
            if(must[i]){
                cur = req[i] - 1;
            }else{
                cur = req[i];
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%lld", a + i);
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}