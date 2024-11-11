def checkPrime(m):
    for i in range(2,(m//2)+1):
        if m%i==0:
            return True
    return False
def compositeNumber(n):
    j=4
    while j<n:
        if checkPrime(j):
            if checkPrime(n-j):
                print(j,n-j)
                break
        j+=1

n=int(input())
compositeNumber(n)