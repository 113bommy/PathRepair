import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

S = input().rstrip()
T = input().rstrip()

S,T

# Sの方が長くする
LS = len(S)
LT = len(T)
n = (LT + (-LT) % LS) // LS
S *= (n+1)
S = S[:LS+LT]

MOD = 10 ** 16 + 61
base = 12345
base_inv = pow(base,MOD-2,MOD) 
power = [1] * (LS+LT)
power_inv = [1] * (LS+LT)
for n in range(1,LS+LT):
    power[n] = power[n-1] * base % MOD
    power_inv[n] = power_inv[n-1] * base_inv % MOD

def to_rolling_hash(S):
    ret = [0] * len(S)
    for i,s in enumerate(S):
        ret[i] = (ret[i-1] + power[i] * ord(s)) % MOD
    return ret

S_hash = to_rolling_hash(S) + [0]
T_hash = to_rolling_hash(T)[-1] # 文字列全体

can_start = [(S_hash[i + LT - 1] - S_hash[i - 1]) * power_inv[i] % MOD == T_hash for i in range(LS)]

INF = 10 ** 18
visited = [False] * LS
dp = [None] * LS

arr = [INF] * LS

q = [(i,0) for i,bl in enumerate(can_start) if not bl]

while q:
    qq = []
    for x,d in q:
        if arr[x] == INF:
            arr[x] = d
            qq.append(((x-LT)%LS, d+1))
    q = qq

answer = max(arr)

if answer >= INF:
    answer = -1

print(answer)