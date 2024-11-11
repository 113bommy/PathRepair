n=int(input())
for i in range(n):
    h=int(input())
    f=list(map(int,input().split()))
    f.sort()
    mini=f[-1]-f[0]
    for j in range(h-1):
        for k in range(j+1,h):
            if f[k]-f[j]<mini:
                mini=f[k]-f[j]
    print(mini)