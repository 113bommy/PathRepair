n = int(input())
k = 0
for i in range(0, n):
    arr = list(map(int, input().split()))
    m = sum(1 for j in arr if j == 1)
    if (m >= 2):
        k = k + 1
print(k)