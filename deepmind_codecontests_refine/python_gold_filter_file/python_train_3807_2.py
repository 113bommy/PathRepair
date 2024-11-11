from math import sqrt
def prime_check(n):
    flag=1
    for i in range(3,int(sqrt(n))+2,2):
        if (n%i==0):
            flag=0
            break
    return (flag)
n=int(input())
arr=[0,0,1,1,2,1,2,1,2,2,2]
if (n<=10):
    print (arr[n])
else:
    if (n%2==0):
        print (2)
    else:
        if (prime_check(n)):
            print (1)
        elif (prime_check(n-2)):
            print (2)
        else:
            print (3)
