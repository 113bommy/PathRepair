n = int(input())
s = input()
len = 1000000000
ans = int(s)
for i in range(0, n-1):
    if s[i+1] != '0':
        len = min(len, max(i+1, n-i-1))
for i in range(0,n-1):
    if max(i+1, n-i-1) == len and s[i+1] != '0':
        ans = min(ans, int(s[0:i+1])+int(s[i+1:n]))
print(ans)