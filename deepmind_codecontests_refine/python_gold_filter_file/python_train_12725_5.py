import sys
input = sys.stdin.readline
mod = 998244353
N, M, L, R = map(int, input().split())
if N*M % 2 == 1:
    print(pow(R-L+1, N*M, mod))
else:
    ans1 = pow(R-L+1, N*M, mod)
    if (R-L)%2==1:
        ans2 = 0
    else:
        ans2 = 1
    ans = (ans1 + ans2) * pow(2, mod-2, mod) % mod
    print(ans)
