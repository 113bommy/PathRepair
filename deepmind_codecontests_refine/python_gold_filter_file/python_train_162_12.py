
l,r = list(map(int,input().split()))

def prime(num):
    n1 = num-1 
    n2 = num +1 
    if(n1%6==0 or n2%6 ==0):
        return True
    return False


if(l==r):
    if(prime(l) or l==3):
        print(l) 
    else:
        print(2)
else:
    print(2)

