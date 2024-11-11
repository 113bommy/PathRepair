a, b = map(int, input().split())
c = sorted(map(int, input().split()))
print(sum(c[:b]))