n=int(input())
for i in range(n):
    f=[int(x) for x in input().split()]
    if (f[1]-f[0])%(f[2]+f[3])==0:
        print((f[1]-f[0])//(f[2]+f[3]))
    else:
        print(-1)