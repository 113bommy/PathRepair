import math

n = int(input())
s = input()
s = [int(s[x]) for x in range(n)]
ans = [0 for i in range(n)]
f = [int(x) for x in input().split()]
flag = 0
for i in range(n):
    if(s[i] >= f[s[i]-1] and flag==0):
        ans[i] = s[i]
    if(s[i]<f[s[i]-1] and  flag == 0):
        flag = 1
        ans[i] = f[s[i]-1]
    if(flag == 1 and s[i]<=f[s[i]-1]):
        ans[i] = f[s[i]-1]
    if(flag == 1 and s[i]>f[s[i]-1]):
        flag = 2
        ans[i] = s[i]
    if(flag == 2):
        ans[i] = s[i]
    #print(flag)

for i in range(n):
    ans[i] = str(ans[i])

print("".join(ans))
        