n=int(input())
a=list(map(int,input().split()))
a.sort()
k=n-1
for i in range(3,n):
    if(a[i]!=a[2]):
        k=i-1
        break
if(a[1]!=a[2]):
    print(k-1)
elif(a[0]!=a[1]):
    print(k*(k-1)//2)
elif(a[0]==a[1]):
    ans=(k+1)*k*(k-1)//6
    print(ans)
    