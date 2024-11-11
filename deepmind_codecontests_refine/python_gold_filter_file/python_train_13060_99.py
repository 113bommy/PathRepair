n = int(input())
if  n % 2 == 0:
    print(n-4,4)
else:
    x = 9
    y = n - 9
    for i in range(1,y):
        if y % i == 0:
            print(x,y)
            break
        if i == y//2:
            x = 8
            y = n - 8
            for j in range(1,y):
                if y % j == 0:
                    print(x,y)
                    break     
            break
        
                            
    
            
        

                   
    

        





