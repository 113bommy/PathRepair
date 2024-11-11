def minDiff(n):
    return 2**(n//2+1)-2
t = int(input())
for _ in range(t):
    n = int(input())
    print(minDiff(n))
    