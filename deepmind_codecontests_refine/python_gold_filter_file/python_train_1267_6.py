n,x,y = map(int,input().split())
a = list(map(int,input().split()))
a.insert(0,0)
for i in range(1,n+1):
    c=0
    p = i-x
    if(p<1):
        p=1
    f = i+y
    if(f>n):
        f=n
    for j in range(p,i):
        if(a[i]<a[j]):
            c+=1
    for j in range(i+1,f+1):
        if(a[i]<a[j]):
            c+=1
    if(c==i-p + f-i):
        print(i)
        break