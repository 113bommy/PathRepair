n = int(input())

prime = [ 2, 3, 5, 7, 11 ]
flag_x = True
flag_y = True
x = n//2
y = n - (n//2)

while flag_x or flag_y :
    flag_x = True
    flag_y = True
    for i in prime :
        if x%i == 0 and x not in prime :
            flag_x = False
            break
            
    for i in prime :
        if y%i == 0 and y not in prime :
            flag_y = False
            break
    
    if flag_x or flag_y :
        x -= 1
        y += 1
    
print(x,y)