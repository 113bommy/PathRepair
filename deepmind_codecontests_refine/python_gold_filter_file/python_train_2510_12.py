import math
a = int(input())
sum = 0
for i in range(1,int(math.sqrt(a))+1):
    if(a % i == 0):
        sum += 1
        if(a / i != i):
            sum += 1
print(sum)