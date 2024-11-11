from itertools import combinations
import math
num , k  = map(int , input().split())
result = []
counter = 1
while num % 2 == 0:
    result.append(2)
    num /= 2
for i in range(3 , int(num ** .5) + 1 ,2):
    while num % i == 0:
        result.append(i)
        num /= i
if num > 2:
    result.append(num)
if len(result) < k:
    print(-1)
    exit(0)
for i in range(k- 1):
    print(result[i]  , end = " ")
for i in range(k - 1 , len(result)):
   counter *= result[i]
print(int(counter) , end = " ")



