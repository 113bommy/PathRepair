#import time

num =int(input())

#start = time.time()
a = 0

b = 0
c = 0
q = [0,0]
kr = [0,0,0,0]
output = False

def sum0():
    s = a*1234567
    return s
def sum1():
    s = a*1234567+b*123456
    return s
def sum2():
    s = a*1234567+b*123456+c*1234
    return s


q[0] = int(num/1234567)
if (num % 1234567) == 0:
    output = True
if (num % 123456) == 0:
    output = True
if (num % 1234) == 0:
    output = True

while a <= q[0]:

    q[1] = int((num - sum0())/123456)
    while b <= q[1]:
        c = int((num - sum1())/1234)
        d = int((num - sum2())/56)

        if (((num - sum2()) % 56) == 0) and ((d)<=(c/100)):
            output = True
            #kr=[sum0(),sum1(),sum2(),a,b,c]
            break
        else:
            b += d

            
        c = 0
        b += 1
    if output == True:
        break
    b = 0
    a += 1

  

if output == True:
    print("YES")
else:
    print("NO")
#print(kr)
#print(num - sum2())
#end = time.time()
#print(end - start)

