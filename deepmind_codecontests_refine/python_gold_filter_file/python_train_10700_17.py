# D - Dice in Line
n,k = map(int,input().split())
p = [0]*k + list(map(int,input().split()))
ans = sum = 0
for i in range(n):
    sum += p[i+k] - p[i]
    ans = max(ans, sum)
print((ans+k)/2)