MOD = 998244353

N,M,K = map(int,input().split())

ans = 0
NCi = 1#nからi選ぶ組み合わせ
for i in range(0,K+1,1):
    ans = (ans + M * pow(M-1,N-1-i,MOD)*NCi)%MOD
    NCi = (NCi*(N-1-i) * pow((i+1),MOD-2,MOD))%MOD

print(ans)