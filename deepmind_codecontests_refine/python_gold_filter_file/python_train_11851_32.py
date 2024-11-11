N = int(input())
ans = []
n = N//2
if N == 3:
    ans = [2,5,63]
elif 4 <= N <= 15000:
    for i in range(1,n):
        ans.append(2*i)
        x = 30000 - 2*i
        ans.append(x)
    if N % 2 == 1:
        ans.append(30000)
    ans.append(3)
    ans.append(9)
else:
    for i in range(1,15000):
        ans.append(2*i)
    x = N - 14999
    for j in range(x-1):
        y = 6*j + 3
        ans.append(y)
    if x % 2 == 1:
        ans.append(30000)
    else:
        ans.append(6*x - 3)
print(*ans)
    
