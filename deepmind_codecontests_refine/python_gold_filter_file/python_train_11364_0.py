#n = int(input())
#n, m = map(int, input().split())
#d = list(map(int, input().split()))

n = int(input())
d = list(map(int, input().split()))
t = 10**9

for i in range(1, n+1):
        j = max(i - 1, n - i)
        t = min(t, d[i-1]//j)
print(t)