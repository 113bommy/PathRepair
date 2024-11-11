

import sys
import math 

strInp = lambda : input().strip().split()
intInp = lambda : list(map(int,strInp()))

n = int(input())
arr = set(intInp())

if len(arr) > 3:
    print(-1)
else:
    arr = list(arr)
    if len(arr) == 3 :
        
        arr.sort()
        if arr[1] - arr[0] == arr[2] - arr[1]:
            print(arr[1] - arr[0])
        else:
            print(-1)    
    elif len(arr) == 2:
        arr.sort()
        if sum(arr) % 2 == 0:
            print(sum(arr)//2 - arr[0])
        else:
            print(arr[1]-arr[0])    
    else:
        print(0)       
  
