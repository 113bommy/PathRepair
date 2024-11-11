a=input()
n=int(a.split()[0])
m=int(a.split()[1])
b=input()
l=list(map(int,b.split()))
l.sort()
h=0
k=0
for i in range(n):
    if(h<l[n-1] and l[i]>=h+1):
        h=h+1
        k=k+1
    else:
        k=k+1
k=k+l[n-1]-h
print(sum(l)-k)