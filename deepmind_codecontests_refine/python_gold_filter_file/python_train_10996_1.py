from sys import stdin, stdout

INF = float('inf')
n = int(stdin.readline())
count = [0, 5, 50, 500, 5000, 50000, 500000, 5000000, 50000000, 500000000, INF]

for label in range(len(count)):
    if count[label + 1] > n:
        break

pref = 0
value = int(str(pref) + '9' * label)
ans = 0

while value <= n - 1 + n:
    
    if n < 5:
        ans = n * (n - 1) // 2
        break
    
    k = max(value - n, 1)
    ans += (min(n, value - 1) - k + 1) // 2
    
    pref += 1
    value = int(str(pref) + '9' * label)

stdout.write(str(ans))