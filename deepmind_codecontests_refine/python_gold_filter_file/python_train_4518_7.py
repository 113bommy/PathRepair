import sys

def bp(a, b):
    if(b == 0):
        return 1
    if(b&1):
        return a * bp(a, b -1)
    c = bp(a, b>>1)
    return c*c

a, b, n = map(int, input().split())
if(a == 0):
    if(b == 0):
        print(1)
    else:
        print("No solution")
else:
    if(b % abs(a)):
        print("No solution")
    else:
        c  = b//a
        if(c < 0):
            if(n&1):
                d = int(pow(abs(c), 1.0/n))
                d = round(d, 0)
                flag, ans = 0, -1
                for i in range(-1, 2, 1):
                    cur = d + i
                    if(bp(cur, n) == abs(c)):
                        flag = flag + 1
                        ans = cur
                if(flag):
                    print(-ans)
                else:
                    print("No solution")
            else:
                print("No solution")
        else:
            d = int(pow((c), 1.0/n))
            flag, ans = 0, -1
            for i in range(-1, 2, 1):
                cur = d + i
                if(bp(cur, n) == c):
                    flag = flag + 1
                    ans = cur
            if(flag):
                print(ans)
            else:
                print("No solution")