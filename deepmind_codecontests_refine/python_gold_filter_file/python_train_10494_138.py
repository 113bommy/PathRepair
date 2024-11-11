n, a, b, c, d  = map(int, input().split())
s = input()
ans = 'Yes'
if '##' in s[a-1:max(c,d)]:
    ans = 'No'
else:
    if c > d and '...' not in s[b-2:d+1]:
        ans = 'No'
print(ans)