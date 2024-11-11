
inp = int(input().strip())
l = []
for i in range(inp):
    a,b = map(int, input().strip().split())
    l.append((a,b))

k = int(input().strip())

i = len(l)
for j in l:
    if k>j[1]:
        i -=1
    else:
        break

print(i)
        