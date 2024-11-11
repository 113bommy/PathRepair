def binary_search(arr, low, high, x):
 
    if high >= low:
 
        mid = (high + low) // 2
 
        if arr[mid] == x:
            return 1
 
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        return 0

import math
n = int(input())
n = n*(1+1)
t = []
flag = 1
for i in range(1,int(math.sqrt(n))+1):
    t.append(i*(i+1))
k = len(t)-1
for i in range(1,int(math.sqrt(n))+1):
    if(binary_search(t,0,k,n-i*(i+1))):
        print("YES")
        flag = 0
        break
if(flag):
    print("NO")