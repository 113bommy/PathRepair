
for __ in range(int(input())):
    r,c = map(int,input().split())
    
    if c%2 == 0:
        print(r*(c//2))
    else:
        if r%2 != 0:
            print( ((r+1)//2)*((c+1)//2) + ((r+1)//2 - 1)*((c-1)//2) )
        else:
            print( ((r)//2)*((c+1)//2) + ((r)//2)*((c-1)//2) )