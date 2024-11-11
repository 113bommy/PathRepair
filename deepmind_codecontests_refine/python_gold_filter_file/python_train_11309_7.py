n = int(input())
a = int(input())
b = int(input())
x = 0
while True:
    y = (n-x*a)/b
    if y < 0:
        print('NO')
        break
    if int(y) == y:
        print("YES")
        print(x,int(y))
        break
    else:
        x += 1