n=int(input())
a=list(map(int,input().split()))
b=0
for _ in a:
    for i in range(n-1,0,-1):
        if a[i]<a[i-1]:
            a[i],a[i-1]=a[i-1],a[i]
            b+=1
print(*a)
print(b)