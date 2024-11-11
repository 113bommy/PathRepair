n, a, b, c, d = map(int, input().split())
s = input()

ans = 'Yes'
if s[a:c].find('##') > -1:
    ans = 'No'
elif s[b:d].find('##') > -1:
    ans = 'No'
else:
    if d < c:
        if s[b-2:d+1].find('...') == -1:
            ans = 'No'

print(ans)
