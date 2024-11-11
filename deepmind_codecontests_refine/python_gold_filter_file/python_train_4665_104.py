n = int(input())
t = sorted(list(map(int, input().split())))
print(t[n//2] - t[n//2 - 1])

