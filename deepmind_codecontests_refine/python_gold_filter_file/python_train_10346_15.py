a=list(map(int,input().split()))
n=int(a[0])
k=int(a[1])
max=-1000000000
j=0
m=[0]*n
for i in range(n):
    m=list(map(int,input().split()))
    f=int(m[0])
    t=int(m[1])
    if t>k:
        j=f-(t-k)
        if j>max:
            max=j
    else:
        j=f
        if j>max:
            max=j
print(max)
