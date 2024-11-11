n, h = [int(x) for x in input().split()]

a = [int(x) for x in input().split()]

w = 0

for x in a:
    if x > h:
        w +=  2
        continue
    w += 1

print(w)