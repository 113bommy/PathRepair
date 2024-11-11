z=int(input())
for h in range(z):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    cnt=1
    b=a.copy()
    b.sort()
    m=[b[0]]
    for i in range(1,n):
        if b[i]!=b[i-1]:
            cnt+=1
            m.append(b[i])
    if cnt>k:
        print(-1)
    else:
        print(n*k)
        x=k-cnt
        ans=[]
        for i in range(x):
            m.append(1)
        for i in range(n):
            for j in range(k):
                print(m[j],end=" ")
        print()



