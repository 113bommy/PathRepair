import math
tc =int(input())
 
for _ in range(tc):
    n=int(input())
    arr=[]
    x=0
    y=0
    for i in range(n):
        x,y=input().split()
        x=int(x)
        y=int(y)
        arr.append([x,y])
    arr=sorted(arr)
    y=arr[n-1][0]
    #print(arr)
    arr.sort(key = lambda x: x[1])
    x=arr[0][1]
    #print(arr)
    print(max(y-x,0))