import math
n = int(input())
arr = list(map(int,filter(None,input().split(' '))))
arr = sorted(arr,reverse=True)
num = -1
for a in arr:
    if a>=0:
        sq = math.sqrt(a)
        if sq-math.floor(sq)==0:
            continue
        else:
            num = a
            break
    else:
        num = a
        break
print(num)