n = int(input())
a = list(map(int,input().split()))

a = sorted(a)
result = 0
for i in range(n):
    result = result + abs(i + 1 - a[i])
print(result)
