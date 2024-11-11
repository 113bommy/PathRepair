N,M = map(int, input().split())
am = list(map(int, input().split()))
c = [0,2,5,5,4,5,6,3,7,6]
f = [-1]*10010
f[0]=0
for i in range(1,N+1):
    for x in am:
        if i-c[x] >= 0:
            f[i] = max(f[i], f[i-c[x]]*10 +x)
            
print(f[N])