n = int(input())
x = list(input())
f = dict(zip(range(1,10), map(int, input().strip().split())))

for i in range(n):
    p = int(x[i])
    if p<f[p]:
        while i<n and int(x[i])<=f[int(x[i])]:
            x[i] = str(f[int(x[i])])
            i += 1
        break
print("".join(x))