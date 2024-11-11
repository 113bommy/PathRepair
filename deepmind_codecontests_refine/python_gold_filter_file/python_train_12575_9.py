n = int(input())
s = input()
ret = 0
for d in range(1, n - 1):
    l = 0
    for i in range(n - d):
        if s[i] == s[i + d]:
            l += 1
        else:
            l = 0
        ret = max(ret, min(l, d))
print(ret)
