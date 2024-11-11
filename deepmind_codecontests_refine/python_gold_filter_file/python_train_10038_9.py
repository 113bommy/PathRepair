n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

c=0
i=0
j=0
while j<m and i<n:
    if b[j]>=a[i]:
        j+=1
        i+=1
    else:
        j+=1
print(n-i)