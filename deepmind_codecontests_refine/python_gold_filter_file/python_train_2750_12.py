n=int(input())
a=input().split()
for i in range(n):
    a[i]=int(a[i])
a.sort()
k,mx,col=1,1,1
for i in range(1,n):
    if a[i-1]==a[i]:
        k+=1
        if k>mx:
            mx=k
    else:
        col+=1
        k=1
print(mx,col)