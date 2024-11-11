a, b, c = map(int, input().split())
print(int(a/(b+c))*b + min(b, a%(b+c)))
