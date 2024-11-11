＃include <cstdio>
using namespace std;
 
const int mod = 1000000007;
 
inline
int modMultiple(int a, int b){return (static_cast<long long>(a) * b) % mod;}
 
int main()
{
    int N;
    scanf("%d\n", &N);
    int result = 1;
    int k = 0;
    for (int i = 0; i < N; ++i){
        int Xi;
        scanf("%d", &Xi); getchar();
        while (Xi < k * 2 + 1){
            result = modMultiple(result, k + 1);
            --k;
        }
        ++k;
    }
    for (; k > 0; --k){
        result = modMultiple(result, k);
    }
    printf("%d\n", result);
}