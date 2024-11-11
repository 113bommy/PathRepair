import random

n=int(input())
array=list(map(int,input().split()))
for i in range(1,n):
    if i % 2 == 0:
       array.remove(min(array))
    else:
        array.remove(max(array))

print(array[0])


