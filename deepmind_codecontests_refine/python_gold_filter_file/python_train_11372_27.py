u, v = [int(x) for x in input().split()]
if u == 0 and v == 0:
    print(0)
    exit(0)

if u == v:
    print(1)
    print(u)
    exit(0)
if u > v or (u-v)%2 == 1:
    print(-1)
    exit(0)

result = 0
tmp_u = u
tmp_and = (v-u) >> 1
x = tmp_and

i = 0
j = 0
# print(bin(tmp_u))
# print(bin(tmp_and))
while tmp_u > 0 or tmp_and > 0:
    a = tmp_and % 2
    b = tmp_u % 2
    if a == 1:
        if b == 1:
            print(3)
            print(u, x, x)
            exit(0)
        if b == 0:
            result = result + (1<<i)
    if b == 1:
        j = i
    tmp_u = tmp_u>>1
    tmp_and = tmp_and>>1
    i += 1

print(2)
print(result, v-result)
