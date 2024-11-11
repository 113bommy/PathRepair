n = int(input())
L = int(n ** 0.5)
i = 1
k = n
a = [0] * 100005
while i <= n:
    j = min(i + L - 1, n)
    while j >= i:
        a[j] = k
        j -= 1
        k -= 1
    i += L

print(" ".join(map(str, a[1:n + 1])))