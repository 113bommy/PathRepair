n = int(input())
s = list(input())

res = 0

for k in range(1,n):
    d = [0]*n
    for i in range(n-k):
        if i+k <= n-1 and s[i] == s[i+k]:
            d[i] = min(k,d[i-1]+1)
            res = max(res,d[i])
print(res)
