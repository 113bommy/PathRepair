#include<cstdio>
#include<algorithm>
using namespace std;

int arr[100005];
int main(){
    int n, x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(!arr[x]){
            arr[x] = 1;
            cnt++;// 记录不重复的数字
        }
    }
    printf("%d\n",(n-cnt)&1?cnt-1:cnt);
    return 0;
}
