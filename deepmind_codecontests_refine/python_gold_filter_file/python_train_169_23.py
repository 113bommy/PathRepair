import sys
n = int(input())
s = input()
ans = '@@'
res = 0
for i in range(n-1):
    r = s[i] + s[i+1]
    cnt = 1
    for j in range(i+1,n-1):
        if s[j] + s[j+1] == r: cnt += 1
    if cnt > res:
        res = cnt
        ans = r
print(ans)