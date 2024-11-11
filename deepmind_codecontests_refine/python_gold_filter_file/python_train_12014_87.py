import math
def isPrime(n):
    if n== 1 or n==3 or n==5:
        return True
    sqn = int(math.sqrt(n)) + 1
    for i in range(3,sqn,2):
        if n%i==0:
            return False
    return True


n = int(input())
i = 3
count = 0
arr = []
while count<n:
    if isPrime(i):
        arr.append(i)
        count+=1
    i+=2

for ele in arr:
    print(ele,end=" ")