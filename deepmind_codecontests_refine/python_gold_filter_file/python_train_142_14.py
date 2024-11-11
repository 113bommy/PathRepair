s = input().split('+')
s = [int(i) for i in s]
a = sorted(s)
ans = ''
for i in range(len(s)):
    if i == len(s)-1:
        ans += str(a[i])
    else:
        ans += str(a[i]) + '+'
print(ans)
