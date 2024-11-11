n, m, k = list(map(int, input().split()))
x = list(map(int, input().split()))
a = []
maximum = n + 1
for i in range(n):
    if x[i] != 0 and x[i] <= k:
        abc = (x[i], i)
        a.append(abc)
for j in range(len(a)):
    if a[j][0] <= k and abs((m - a[j][1]) - 1) < maximum:
        maximum = m - a[j][1]
print(abs((maximum - 1) * 10))
