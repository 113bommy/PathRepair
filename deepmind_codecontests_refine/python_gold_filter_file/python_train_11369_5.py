x = input()
level = -1

while len(x) > 0:
    if x[1] != '/':
        level += 1
        print(level * '  ' + x[:3])
        x = x[3:]
    else:
        print(level * '  ' + x[:4])
        x = x[4:]
        level -= 1
        
        
    
