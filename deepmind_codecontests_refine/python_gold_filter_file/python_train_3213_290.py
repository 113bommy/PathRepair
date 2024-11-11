a, b, x = map(int, input().split())
res = int(b//x - (a-1)//x)
print(res)