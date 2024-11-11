n,k=map(int,input().split())
a=list(map(int,input().split()))
avg=0
for i in range(n-k+1):
    su=sum(a[i:i+k])
    m=k
    avg=max(avg,su/m)
    for j in range(i+k,n):
        su+=a[j];m+=1
        avg=max(avg,su/m)
print(avg)