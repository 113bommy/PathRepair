n, m = map(int,input().split())
ai = list(map(int,input().split()))
maxn = 10**9+1
bi = list(map(int,input().split()))+[maxn]
mod = 998244353
bi2 = [0] * m
bi3 = [0] * m
j = m-1
temp = 0
for i in range(n-1,-1,-1):
    if ai[i] == bi[j]:
        temp = 1
        bi2[j] = i
        j -= 1
        if j == -1:
            break
        continue
    elif ai[i] < bi[j]:
        j = -2
        break
    if ai[i] >= bi[j+1] and temp == 1:
        bi3[j] += 1
    else:
        temp = 0
if j != -1 or min(bi) > min(ai):
    print(0)
else:
    ans = 1
    for i in range(m-1):
        ans *= bi3[i]+1
        ans %= mod
    print(ans)
