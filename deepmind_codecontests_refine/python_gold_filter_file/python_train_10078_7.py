n = int(input())
a = sorted(list(map(int, input().split())))

for i in range(n-1):
    if a[i]+a[i+1] < 0:
        a[i] = -a[i]
        a[i+1] = -a[i+1]

print(sum(a))