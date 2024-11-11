R,G,B,N = map(int,input().split())

ans = 0
for b in range(N+1):
    for g in range(N+1):
        if N-B*b-G*g >= 0 and (N-B*b-G*g)%R == 0:
            ans += 1
print(ans)

