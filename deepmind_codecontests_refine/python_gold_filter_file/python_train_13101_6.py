N,C,K=map(int,input().split())
T=[int(input()) for _ in range(N)]

T.sort()

bus=-10**9
cnt=0
ans=0
for t in T:
    if t>bus or cnt>=C:
        bus=t+K
        cnt=1
        ans+=1
    else:
        cnt+=1

print(ans)