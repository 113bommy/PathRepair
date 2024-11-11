from collections import defaultdict
import math
xx = defaultdict(int)
i = int(input())
min = 101
max = 1
sum = 0


def getDivisors(n, div) : 
      
    # Note that this loop runs till square root 
    i = 1
    while i <= math.sqrt(n): 
          
        if (n % i == 0) : 
              
            # If divisors are equal, print only one 
            if (n / i == i) : 
                div.append(i) 
            else : 
                # Otherwise print both 
                div.append(i) 
                div.append(n/i) 
        i = i + 1

a = list(map(int, input().split()))
for x in a:
    xx[x] = x
    sum += x


pm = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

for x in xx:
    if min > x:
        min = x

mintmp = 0
for x in xx:
    div = []
    getDivisors(x, div)
    
    for y in div:
        tmp = int(x/y + min*y - x - min)
        if tmp < mintmp:
            mintmp = tmp

sum += mintmp

print(sum)

