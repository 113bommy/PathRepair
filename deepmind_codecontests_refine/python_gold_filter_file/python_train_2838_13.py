for _ in range(int(input())):
    x,y,z = map(int,input().split())
    mx = max(x,y,z)
    if [x,y,z].count(mx)<2:
        print("NO")
        continue
    print("YES")
    if x==mx and y==mx:
        print(mx,z,z)
    elif x==mx and z==mx:
        print(mx,y,y)
    elif z==mx and y==mx:
        print(mx,x,x)