n, k = map(int, input().split())
d = map(str, input().split())
digits = set(d)
num = {str(i) for i in range(0,10)}
left = num - digits
for i in range(n, 100000):
    Nums = set(str(i))
    if Nums <= left:
        print(i)
        break