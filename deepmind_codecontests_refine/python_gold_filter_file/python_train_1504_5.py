n = int(input())
i = -2*10**9
j = 2*10**9
while n > 0:
    sign,x,ans = input().split()
    x = int(x)
    if sign == ">":
        if ans == "Y":
            if i < x+1:
                i = x+1
        else:
            if j > x-1:
                j = x
    elif sign == ">=":
        if ans == "Y":
            if i < x:
                i = x
        else:
            if j > x:
                j = x-1
    elif sign == "<":
        if ans == "Y":
            if j > x-1:
                j = x-1
        else:
            if i < x+1:
                i = x
    else:
        if ans == "Y":
            if j > x:
                j = x
        else:
            if i < x:
                i = x+1
    if i > j:
        break
    #print(i,j)
    n-=1
if i > j:
    print("Impossible")
else:
    print(i)