import math
#


def test():
    n, a, b = map(int, input().split())
    if(a+b > n-2 or abs(a-b) > 1):
        print('-1')
    else:
        if(a == b):
            i = 2
            s = '1 '
            while(a > 0):
                a -= 1
                s += str(i+1)+" "+str(i)+" "
                i += 2

            for i in range(i, n+1):
                s += str(i)+' '

            print(s)
        elif(a > b):
            i = 2
            s = '1 '
            while(b > 0):
                b -= 1
                s += str(i+1)+" "+str(i)+" "
                i += 2

            while(n >= i):
                s += str(n)+' '
                n -= 1

            print(s)
        else:
            i = n-1
            s = str(n)+" "
            while(a > 0):
                a -= 1
                s += str(i-1)+" "+str(i)+" "
                i -= 2

            n = 1
            while(n <= i):
                s += str(n)+" "
                n += 1

            print(s)


# rjkkbxtcndj pfgecrjd
t = int(input())
for i in range(t):
    test()
