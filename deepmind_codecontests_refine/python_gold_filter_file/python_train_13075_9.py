n, m = map(int, input().split())
s = input()
t = input()

res = [0] * 10000
for i in range(m - n + 1):
    asd = []
    for j in range(n):
        if t[i + j] != s[j]:
            asd.append(j + 1)   
    if len(asd) < len(res):
        res = asd
print(len(res))
print(*res)
            
            