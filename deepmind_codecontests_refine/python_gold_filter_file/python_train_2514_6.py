n = int(input())
a = list(input())
b = list(map(int,input().split()))
i = 0
while i<n:
    k = int(a[i])
    if b[k-1]>k:
        while i<n and b[int(a[i])-1]>=int(a[i]):
            a[i]=str(b[int(a[i])-1])
            i+=1
        break
    i+=1
print(*a,sep="")