s = input()
ans = True
for i in range(len(s)-1):
    if s[i] not in 'aeioun' and s[i+1] not in 'aeiou':
        ans = False
if s[-1:] not in 'aeioun': ans = False
print('YES' if ans else 'NO')