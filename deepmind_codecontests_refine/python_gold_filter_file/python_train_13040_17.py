a= int(input())
for i in range(a):
    x=int(input())
    y= list(map(int,input().split(" ")))
    z= list(map(int,input().split(" ")))
    if len(y)==1 and len(z)==1:
        print(0)
    else:
        min_y = min(y)
        min_z = min(z)
       # print(min_y, min_z)
        total_moves = 0
        for i in range(x):total_moves+=max((y[i]-min_y),(z[i]-min_z))
        print(total_moves)



    