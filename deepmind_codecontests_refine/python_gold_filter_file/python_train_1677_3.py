s = input()
n = len(s)
ans = [0 for i in range(n)]

for i in range(n-1):
    if s[i]!=s[i+1]:
        ans[i] = 1 
        s = s[:i+1][::-1] + s[i+1:]
if s[-1]=='a':
    ans[n-1] = 1
print(*ans)