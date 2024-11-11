s = list(input())
n = len(s)
ans = [1]*n
for i in range(n-1):
    if s[i] == s[i+1] == "R":
        ans[i+2] += ans[i]
        ans[i] = 0
for j in range(n-1,0,-1):
    if s[j] == s[j-1] == "L":
        ans[j-2] += ans[j]
        ans[j] = 0
print(' '.join([str(a) for a in ans]))