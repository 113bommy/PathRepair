N = int(input())

ans=[0]*(N+1)
t=int(N**0.5+1)
for x in range(1, t):
    for y in range(1, t):
        for z in range(1, t):
            v=x*x+y*y+z*z+x*y+y*z+z*x
            if v<=N: ans[v]+=1
for i in range(1,N+1):
    print(ans[i])