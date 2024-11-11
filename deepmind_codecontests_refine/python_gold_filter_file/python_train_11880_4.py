n = int(input())
x = list(map(int, input().split()))
y = []
y.append(n)
i = n - 2
while x[i] != 1:
    y.append(x[i])
    i = x[i] - 2
y.append(1)
print(*y[::-1])