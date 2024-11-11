import sys
input=sys.stdin.readline
n=int(input())
wf=[list(map(int,input().split())) for i in range(n)]

ans=0
for i in range(n):
    for j in range(i+1,n):
        use=True
        for h in range(n):
            if h!=i and h!=j and wf[i][j] > wf[i][h]+wf[h][j]:
                print(-1)
                exit()
            if h!=i and h!=j and wf[i][j] == wf[i][h]+wf[h][j]:
                use=False
        if use:
            ans+=wf[i][j]
print(int(ans))