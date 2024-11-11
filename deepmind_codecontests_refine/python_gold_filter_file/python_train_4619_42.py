n = int(input())
s = 0
while n:
    p = (input().split())
    if p.count("1") >= 2:
        s += 1
        n -= 1
    else:
        n -= 1
print(s)