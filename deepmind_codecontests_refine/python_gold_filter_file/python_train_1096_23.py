n = int(input())
a = list(map(int, input().split()))

m1 = 0
m2 = 0
for i, v in enumerate(a):
    if v == 1:
        m1 = i + 1
    elif v == n:
        m2 = i + 1
print(max([m1 - 1, n - m1, m2 - 1, n - m2]))
