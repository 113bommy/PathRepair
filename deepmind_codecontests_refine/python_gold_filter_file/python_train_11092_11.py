n = int(input())
s = input()
x = list(map(int, input().split()))
mn = 10000000000
for i in range(n-1):
    if s[i] == 'R' and s[i+1] == 'L':
        if x[i+1] - x[i] < mn:
            mn = x[i+1] - x[i]
if mn == 10000000000:
    print(-1)
else:
    print(mn//2)