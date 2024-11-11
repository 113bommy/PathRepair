d = int(input())
n = int(input())
a = list(map(int, input().split()))
r = 0
for i in range(n - 1):
    r += d - a[i]
print(r)
