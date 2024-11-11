n, x = map(int, input().split())
distress = 0
for i in range(n):
    d = list(map(str, input().split()))
    if d[0] == "+":
        x += int(d[1])
    else:
        if int(d[1]) <= x:
            x -= int(d[1])
        else:
            distress += 1
print(x, distress)