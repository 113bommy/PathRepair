k, n = map(int, input().split())
p = sorted(list(map(int, input().split())))
print(sum(p[:n]))
