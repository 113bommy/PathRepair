# from array import  array

n , k = map(int, input().split())
a = [int(x) for x in input().split()]
b, ans = [0, a[0]], 0.0
for i in range(1, len(a)):
    b.append(b[-1] + a[i])

if n == k:
    ans = b[n] / n
for i in range(n - k + 1):
    for j in range(i + k, min(n + 1, i + 2 * k)):
        ans = max((b[j] - b[i]) / (j - i), ans)

print(ans)
