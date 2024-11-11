def findCircle(x1, y1, x2, y2, x3, y3) :
    try:
        x12 = x1 - x2  
        x13 = x1 - x3  
    
        y12 = y1 - y2  
        y13 = y1 - y3  
    
        y31 = y3 - y1  
        y21 = y2 - y1  
    
        x31 = x3 - x1  
        x21 = x2 - x1
    
        sx13 = x1**2 - x3**2  
    
 
        sy13 = y1**2 - y3**2  
    
        sx21 = x2**2 - x1**2  
        sy21 = y2**2 - y1**2
    
        f = (((sx13) * (x12) + (sy13) * (x12) + (sx21) * (x13) + (sy21) * (x13)) // (2 * (y31) * (x12) - (y21) * (x13)))
                
        g = (((sx13) * (y12) + (sy13) * (y12) + (sx21) * (y13) + (sy21) * (y13)) // (2 * ((x31) * (y12) - (x21) * (y13))))  
    
        c = (-(x1**2) - y1**2 - 2 * g * x1 - 2 * f * y1)
 
        h = -g
        k = -f  
        sqr_of_r = h * h + k * k - c  


        r = sqr_of_r**0.5


    except Exception:
        return False  
  
    return True
  


x1, y1, x2, y2, x3, y3 = map(int,input().split())
m = 1000000007
if findCircle(x1, y1, x2, y2, x3, y3):
    if ((((x1-x2)**2)%m + ((y1-y2)**2)%m)%m) == ((((x2-x3)**2)%m + ((y2-y3)**2)%m)%m):
        print('Yes')
    else:
        print('No')
else:
    print('No')