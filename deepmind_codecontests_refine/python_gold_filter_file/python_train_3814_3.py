a1 = '31 28 31 30 31 30 31 31 30 31 30 31 '
a2 = '31 29 31 30 31 30 31 31 30 31 30 31 '
s = a1+a1+a1+a2+a1+a1
t = int(input())
a = input().strip()
ans = 'NO'
if a in s:
    ans = 'YES'
print(ans)