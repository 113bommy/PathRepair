s = input()
c = s[0]
d = s[1]
f1 = 'a' < c < 'h'
f2 = '1' < d < '8'
if f1 and f2: ans = 8
elif f1 or f2: ans = 5
else: ans = 3
print(ans)
