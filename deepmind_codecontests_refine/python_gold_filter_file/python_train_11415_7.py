l, r = map(int, input().split())
two = []
t = 1
two.append(t)
while t * 2 <= r:
    t *= 2
    two.append(t)
t = 1
three = []
three.append(t)
while t  * 3 <= r:
    t *= 3
    three.append(t)
count = 0
for i in two:
    for j in three:
        if i * j <= r and i * j >= l:
            count += 1
print(count)


