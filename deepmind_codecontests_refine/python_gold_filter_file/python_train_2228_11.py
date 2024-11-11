nm=input()
nm=nm.split(" ")
n=int(nm[0])
m=int(nm[1])
f=input()
f=f.split(" ")
for i in range(m):
    f[i]=int(f[i])
if n==m:
    print(max(f)-min(f))
else:
    f.sort()
    gap=set()
    for i in range(m-n+1):
        gap.add(f[i+n-1]-f[i])
    print(min(gap))