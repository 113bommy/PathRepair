a = int(input())
b = int(input())
def bo0(x):
    so = 0
    i = 0
    while(True):
        if(x in range (10)):
            return so + x*(10 ** i)
        so = so + (x % 10)*(10**i)
        if (x % 10 != 0):
            i += 1 
        if (x % 10 == 0):
            i == i
        x = x // 10
    return(so)
a1 = bo0(a)
b1 = bo0(b)
c1 = bo0(a+b)
if (a1 + b1 == c1):
    print("YES")
else:
    print("NO") 