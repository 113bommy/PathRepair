n=int(input())-1
for val in range(1,10**6):
    x=n
    Bool = False
    A,B=val,0
    if x%val == 0 and x > 0:
        x = x//val
        x -= (val+1)
        if x%2 == 0 and x >0:
            B=x//2
            Bool=True
            print(A,B)
            break
if Bool==False:
    print("NO")
    
            