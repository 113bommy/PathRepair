def isprime(x):

    if x <= 1 :
        return False
    if x <= 3 :
        return True

    if (x % 2 == 0 or x % 3 == 0 ):
        return False

    i = 5

    while(i * i <= x):
        if (x % i == 0 or x % (i+2) == 0 ):
            return False
        i = i + 6

    return True

n , m  = map(int,input().split())
k = 50
c = 0
for i in range(n+1 ,k+1 ):
    if isprime(i) == True :
        c = i
        break
if c == m :
    print('YES')
    exit()
else:
    print('NO')
    exit()