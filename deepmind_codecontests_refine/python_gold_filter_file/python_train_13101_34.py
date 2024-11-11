N, C, K = map(int,input().split())
T = [int(input()) for k in range(N)]
T = sorted(T)

p = C
d = T[0]+K
ans = 1
for t in T:
    if p == 0 or t > d:
        d = t+K
        p = C-1
        ans += 1
    else:
        p -= 1

print(ans)