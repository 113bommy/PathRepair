I = lambda: map(int, input().split())
n, m = I()
s, t = input(), input()
res = 0
res_details = []
for i in range(m-n+1):
    #print(t[i:i+n])
    eq = 0
    detail = []
    for j in range(i,i+n):
        if not (ord(s[j-i]) - ord(t[j])):
            eq += 1
        else:
            detail.append(j-i+1)
    if eq >= res:
        res = eq
        res_details = list(detail)
print(n-res)
print(*res_details)
