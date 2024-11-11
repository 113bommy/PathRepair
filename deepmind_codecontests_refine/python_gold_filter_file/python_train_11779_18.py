[x,y,z] = [int(x) for x in input().split()]

[a,b,c] = [int(x) for x in input().split()]

if a < x:
    print('NO')
    exit()

a -= x

if a+b < y:
    print('NO')
    exit()

a -= y

if a+b+c < z:
    print('NO')
    exit()

a -= z
# print(a,b,c)
print('YES')