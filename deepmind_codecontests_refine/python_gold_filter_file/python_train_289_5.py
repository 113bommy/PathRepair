import re
s = input()
k = 'keyence'
ans = 'NO'
for i in range(len(k)):
    a = '^'+k[:i]+'.*?'+k[i:]+'$'
    if re.match(a,s):
        ans = 'YES'
print(ans)
