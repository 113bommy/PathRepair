n,k=map(int,input().split())
a=list(map(int,input().split()))
b=[]
z=True
if n<k:
    print('NO')
elif n==k:
    ans=[]
    for i in range(n):
        ans.append(i+1)
    print('YES')
    print(*ans)
else:
    for i in range(k+1):
        b.append([])
    for i in range(0,k):
        b[i+1].append(a[i])
    for i in range(k,n):
        j=1
        while j<k+1 and a[i] in b[j]:
            j+=1
        if j!=k+1:
            b[j].append(a[i])
        else:
            z=False
    #print(b)
    if z:
        ans=[]
        for x in a:
            j=1
            while x not in b[j] and j<k:
                j+=1
            ans.append(j)
            #print(b[j])
            b[j].pop(b[j].index(x))
        print('YES')
        print(*ans)
    else:
        print('NO')