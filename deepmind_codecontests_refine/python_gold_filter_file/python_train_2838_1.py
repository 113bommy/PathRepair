t = int(input())
for _ in range(t):
    x,y,z = sorted(map(int,input().split()))
    #ab ac bc
    if y == z:
        print ("YES")
        print (x,x,z)
    else:
        print ("NO")