N,C,K = map(int,input().split())
T = [int(input()) for _ in range(N)]
T.sort()
time = T.pop(0)
people = 1
ans = 1
for t in T:
    if t <= time + K and people < C:
        people += 1
    else:
        time = t
        people = 1
        ans += 1
print(ans)
