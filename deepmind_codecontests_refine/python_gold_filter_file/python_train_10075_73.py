n, s = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353

temp = [1] + [0] * s
for i in range(n):
    temp2 = [0] * (s + 1)
    for j in range(s + 1):
        temp2[j] += temp[j] * 2
        temp2[j] %= mod
    for j in range(s + 1 - a[i]):
        temp2[j + a[i]] += temp[j]
        temp2[j + a[i]] %= mod
    temp = temp2
print(temp[s])