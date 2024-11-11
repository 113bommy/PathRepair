n = int(input())
p = list(map(int, input().split()))
p.sort()
print(p[n//2] - p[(n//2)-1])