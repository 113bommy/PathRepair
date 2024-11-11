n,m=map(int,input().split())
v=[int(i) for i in input().split()]
v.sort()
mi=v[-1]-v[0]
for i in range(m-n+1):
    
    if(v[i+n-1]-v[i]<mi):
        mi=v[i+n-1]-v[i]
print(mi)
