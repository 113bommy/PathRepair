n  = int(input())
a = list(map(int, input().split()))
f = [0]*2005;
for i in range(n):
    f[a[i]] = i + 1

for i in range(n):
    for j in range(i):
        if(f[a[i] + a[j]]):
            print(f[a[i] + a[j]], i + 1, j +1  )
            exit()
print(-1)