def readInt():
    return int(input())

def readInts():
    return [ int(i) for i in input().split() ]
    
n = readInt()
a = readInts()

nexts = [-1] * n
heads = [-1] * n
lasts = [-1] * n
cnt = 0

for i in range(n):
    value = a[i]
    
    left = -1
    right = cnt
    
    while right - left > 1:
        mid = (right + left) // 2
        if a[lasts[mid]] < value:
            right = mid
        else:
            left = mid
            
    if right == cnt:
        heads[right] = i
        cnt += 1
    else:
        last = lasts[right]
        nexts[last] = i
    
    lasts[right] = i

for i in range(cnt):
    index = heads[i]
    while index != -1:
        print(a[index], end = ' ')
        index = nexts[index]
    print()
    