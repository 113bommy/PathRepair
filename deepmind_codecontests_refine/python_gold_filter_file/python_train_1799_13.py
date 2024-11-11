for _ in range(int(input())):
    result = 0
    cells = 0
    x=int(input())
    for i in range(1,x+1):
        stair=(2**i)-1
        cells+=int((stair*(stair+1))/2)
        if cells<=x:
           result+=1
        else: break
    print(result)