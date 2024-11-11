N,C,K=map(int,input().split(' '))
T=sorted([int(input()) for i in range(N)])
pas = 1
last_bus=T[0]+K
ans = 1
for i in T[1:]:
    if i <= last_bus and pas < C:
        pas += 1
    else:
        ans += 1
        pas = 1
        last_bus = i+K
print(ans)