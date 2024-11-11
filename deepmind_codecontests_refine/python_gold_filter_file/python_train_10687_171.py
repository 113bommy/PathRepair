n,k=[int(x) for x in input().split()]
if (n>=2 and n<=1000000000 and k>=1 and k<=50):
    for val in range(1,k+1):
        if (n%10==0):
            n=n//10
        else:
            n=n-1
print (n) 