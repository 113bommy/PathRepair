import math
def IsPrime(i):
    flag =0
    if i > 1:
        for j in range(2,int(math.sqrt(i))+1):
            if(i % j == 0):
                flag +=1
        if(flag > 0):
            return False
        else:
            return True
    else:
        return False

Numbers = input().split(" ")
Number1 = int(Numbers[0]) + 1
Number2 = int(Numbers[1])

Count = 0
PrNum=0
while Number1 < Number2:
    if(IsPrime(Number1)):
        Count+=1
    Number1+=1

if(IsPrime(Number2)== False or Count > 0 ):
    print("NO")
elif(Count == 0 and IsPrime(Number2)==True):
    print("YES")