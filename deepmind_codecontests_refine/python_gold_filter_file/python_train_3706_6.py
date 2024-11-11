def is_prime(y):
    d = 2
    flag = 0
    while d < y:
        if y%d == 0:
            flag = 1
            break
        else:
            d +=1
    if flag == 0:
        return y
    else :
        return None

n, m = [int(x) for x in input().split()]
y= n+1
for i in range(m-n):
    t= is_prime(y)
    if t == None:
        y = y +1
    else:
        break
if y==m:
    print('YES')
else:
    print('NO')
