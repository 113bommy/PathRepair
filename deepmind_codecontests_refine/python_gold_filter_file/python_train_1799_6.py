import math

t = int(input())
arr = []

for i in range(t):
    arr.append(int(input()))

k = 0

nice_nums = []
req_squares = []
n = 1

while(True):
    val = 2**n - 1
    nice_nums.append(val)
    req = (val*(val+1))//2
    if(req<=10**18):
        req_squares.append(req)
    else:
        break
    
    n+=1

for i in range(len(arr)):
    max_cells = arr[i]
    ct = 0
    ans = 0
    for j in range(len(req_squares)):
        ct+=req_squares[j]
        if(ct<=max_cells):
            ans+=1
        
        else:
            break

    print(ans)

    
    
            



