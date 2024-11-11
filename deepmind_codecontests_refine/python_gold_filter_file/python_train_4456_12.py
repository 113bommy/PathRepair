n = int(input())
a = []
for i in range(n):
    m = int(input())
    a.append([])
    for i in range(m):
        a[-1].append(list(map(int,input().split())))

ans = 0
for i in range(2**n):
    s = bin(i)[2:].zfill(n)
    f = True
    for j,k in enumerate(a):
        for x,y in k:
            #仮定で正直者なのに証言に矛盾が生じている場合
            if s[x-1] != str(y) and s[j] == '1': f = False
    if f: ans = max(ans, s.count('1'))

print(ans)



