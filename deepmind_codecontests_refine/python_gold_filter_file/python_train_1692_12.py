def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) ]))
def invr():
    return(map(int,input().split()))

n = inp()

for i in range(n):
    l = inlt()

    a = l[0]
    b = l[1]
    f = 1

    count = 0
    while(a % 2 == 0):
        count += 1
        a //= 2
    count2 = 0
    while(b % 2 == 0):
        count2 += 1
        b //= 2

    if(a != b):
        print(-1)
    else:
        dif = abs(count - count2)
        print(((dif % 3) != 0) + dif // 3)
