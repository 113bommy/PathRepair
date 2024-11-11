n,k=list(map(int,input().split()))
if n==k:
    print(-1)
elif n-k==1:
    for i in range(1,n+1):
        print(i,end=' ')
else:
    s=[0]*(n+1)
    j=1
    for i in range(2,k+2):
        s[i]=i
    j=k+3
    bachi=k+2
    #print(s)
    
    for i in range(k+2,n):
        s[i]=j
        if j>n:
            break
        j+=1
        if j>n:
            break
    s.pop(0)
    s[-1]=1
    s[0]=bachi
    print(*s)
        