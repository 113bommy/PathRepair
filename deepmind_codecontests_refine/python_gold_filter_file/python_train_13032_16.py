import math

def divide(b):
    divs = []

    x = int(b)
    for i in range(2, int(math.sqrt(x)+1)):
        if int(x) % int(i) == 0:
            divs.append(int(i))
            while int(x)%int(i)==0:
                x = int(x) // int(i)
    if x > 1:
        divs.append(x)
    return divs

def pow_(n, k, mod):
    ret = 1
    while(int(k) > 0.9):
        if(int(k) % int(2) == 1):
            ret = int(ret) * int(n) % int(mod)
        n = int(n) * int(n) %int(mod)
        k = int(k) // int(2)
    return ret

mod = 1000000007
x , n= input().split()
x = int(x)
n = int(n)
if n>1:
    listdiv = divide(x)
    #print(listdiv)
    ans = 1
    kk = []
    for i in range(len(listdiv)):
        nn = n
        temp = 0
        while True:
            temp = (int(temp) + (int(nn) // int(listdiv[i])))
            nn = int(nn) //int( listdiv[i])
            #print(temp, nn)
            if int (nn) < 1:
                break
        ans *= int(pow_(listdiv[i], temp, mod))
        ans %= int(mod)
        #print("fff")
    print(ans)
else:
    print(1)
