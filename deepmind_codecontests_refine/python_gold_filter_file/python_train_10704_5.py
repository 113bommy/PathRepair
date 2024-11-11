n = int(input())
s = str(input())
W = [0]
for i in range(n):
    if s[i] == "W":
        W.append(W[-1]+1)
    else:
        W.append(W[-1])

ans = n

for i in range(n+1):
    ans = min(ans,W[i] + (n-i)-(W[-1] - W[i]))
print(ans)
