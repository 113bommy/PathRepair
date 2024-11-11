n, k = map(int, input().split())
x = list(map(int, input().split()))

First = [k] * (n + 1)
Last = [-1] * (n + 1)

for i in range(k):
    if (First[x[i]] == k):
        First[x[i]] = i 
    Last[x[i]] = i

result = 0

for i in range(1, n + 1, 1):
    for j in range(i - 1, i + 2, 1):
        if (j > 0 and j <= n):
            if (First[i] > Last[j]):
                result += 1 

print(result)

