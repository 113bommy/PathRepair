import math
for _ in range(int(input())):
    a,b,c = map(int,input().split())
    if c <= a :
        ai,bi  = -1,b
        
    elif c/b >=  a:
        ai,bi = 1,-1
        
    elif c/b < a and a<c:
        
        ai = 1
        bi = b

        
        
    print(ai,bi)
    
    
