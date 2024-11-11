import math


n = int(input())
array = list(map(int, input().split(' ')))

array.append(array[0])

minVal = 100000000000
a = 0
b = 0
for i in range(0, n):
    val = abs(array[i] -  array[i+1])
    if val < minVal:
        a = i
        b = i+1
        minVal = val

b = b%n

a+=1
b+=1

print(a, b)
