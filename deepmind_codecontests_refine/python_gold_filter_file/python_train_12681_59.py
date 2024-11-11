s=input()
t=input()

a=len(s)
b=len(t)

dp=[ [0 for _ in range(a+1)] for _ in range(b+1)]

for j in range(1,b+1):
    for i in range(1,a+1):
        if s[i-1]==t[j-1]:
            dp[j][i]= dp[j-1][i-1]+1
        else:
            dp[j][i]= max(dp[j-1][i],dp[j][i-1])

#print(dp)

ans=""
x=a
y=b
while dp[y][x]!=0:
    if dp[y][x]==dp[y-1][x]:
        y -=1
    elif dp[y][x]==dp[y][x-1]:
        x -=1
    else:
        ans += s[x-1]
        y -=1
        x -=1
print(ans[::-1])