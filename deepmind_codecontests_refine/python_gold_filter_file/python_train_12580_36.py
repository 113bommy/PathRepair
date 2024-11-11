n, k = map(int, input().split())
ls = sorted(list(map(int, input().split())))
print(sum(ls[-k:]))