n = int(input())
p = sorted(list(map(int, input().split())))
print(p[n//2]-p[n//2-1])