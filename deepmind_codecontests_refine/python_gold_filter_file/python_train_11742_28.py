N=int(input())
E=[tuple(sorted(map(int,input().split()))) for i in range(N-1)]

DICT={x:ind for ind,x in enumerate(E)}

EDGE=[[] for i in range(N+1)]
for x,y in E:
    EDGE[x].append(y)
    EDGE[y].append(x)


M=int(input())
Q=[tuple(map(int,input().split())) for i in range(M)]

def dfs(x,y):
    USE=[-1]*(N+1)
    USE[x]=0

    NOW=[x]

    while NOW:
        n=NOW.pop()

        for to in EDGE[n]:
            if USE[to]==-1:
                USE[to]=n
                NOW.append(to)

    ANS=[y]
    while y!=x:
        y=USE[y]
        ANS.append(y)

    RET=[]

    for i in range(1,len(ANS)):
        RET.append(DICT[tuple(sorted([ANS[i-1],ANS[i]]))])

    return set(RET)

Q2=[dfs(x,y) for x,y in Q]

DP=[0]*(1<<M)
DP[0]=1

for i in range(N-1):
    B=0
    for k in range(M):
        if i in Q2[k]:
            B+=1<<k
        
    for j in range((1<<M)-1,-1,-1):
        DP[j|B]+=DP[j]

print(DP[-1])
        
    
