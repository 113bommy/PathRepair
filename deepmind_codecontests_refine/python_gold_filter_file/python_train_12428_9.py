n = int(input())
a = list(map(int, input().split()))
a.sort()
s = 0
for i in range(n):
    s += abs(a[i] - i - 1)
print(s)

