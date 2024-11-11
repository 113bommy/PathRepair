from math import ceil
def bina(a):
    global array
    low,high = 0,len(array)
    while low<high:
        mid = low+((high-low)//2)
        if array[mid]>=a:
            high = mid
        else:
            low = mid+1
    return high
for _ in range(int(input())):
    global array
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    mx = float("-inf")
    s = 0
    array = []
    for i in a:
        s+=i
        mx = max(mx,s)
        array.append(mx)
    for i in range(m):
        x = b[i]
        if s<=0:
            if x>mx:
                print(-1,end = " ")
            else:
                print(bina(x),end = " ")
        else:
            sub = max(0,ceil((x-mx)/s))
            print(n*sub + bina(x-(s*sub)),end = " ")
    print()
