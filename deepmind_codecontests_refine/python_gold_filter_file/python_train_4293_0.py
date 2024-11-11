import sys
#input=sys.stdin.readline
t=int(input())
while t:
    t-=1
    n=int(input())
    b=list(map(int,input().split()))
    l=[i for i in range(1,2*n+1) if i not in b]
    ans=[]
    k=0
    for i in range(n):
        c=0
        ans.append(b[i])
        for j in range(n):
            if l[j]>b[i] and l[j] not in ans:
                c=1
                break
        if c==1:
            ans.append(l[j])
        else:
            k=1
            print(-1)
            break
    if k==1:
        continue
    else:
        print(*ans)
        