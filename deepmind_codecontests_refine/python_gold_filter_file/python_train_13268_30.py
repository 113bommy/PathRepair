s = int(input())
e = 0
for i in range(s):
    p, q = map(int, input().split())
    if q - p >= 2:
        e += 1
print(e)