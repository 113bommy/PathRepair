t = int(input())
while t:
    t-=1
    r,g,b = map(int,input().split())
    arr = [r,g,b]
    arr.sort()
    r,g,b = arr
    if (g+r+1)>=b:
        print("Yes")
    else:
        print("No")
