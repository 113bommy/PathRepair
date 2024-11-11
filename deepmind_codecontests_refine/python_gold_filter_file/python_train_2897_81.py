n = int(input())
s = [input() for _ in range(n)]
result = 0
for i in range(n):
    h = True
    for x in range(n):
        if all(s[(x+i)%n][y]==s[(y+i)%n][x] for y in range(x, n)):
            continue
        else:
            h = False
            break
    if h:
        result += 1
print(result*n)