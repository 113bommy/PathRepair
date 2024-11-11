n = int(input())
a = list(map(int, list(input())))
f = list(map(int, input().split()))

for i in range(n):
    if a[i] < f[a[i]-1]:
        a[i] = f[a[i]-1]
        for j in range(i+1, n):
            if a[j] <= f[a[j]-1]:
                a[j] = f[a[j]-1]
            else:
                break
        break

for i in a:
    print(i, end='')
print()
