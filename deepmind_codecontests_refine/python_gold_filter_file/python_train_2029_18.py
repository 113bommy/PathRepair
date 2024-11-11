import string
a = input()

if 'AB' in a:
    
    b = a.replace('AB','-',1)
    
    if 'BA' in b:
        print('YES')

    else:
        if 'BA' in a:
        
            a = a.replace('BA','-',1)

            if 'AB' in a:
                print('YES')
        
            else:
                print('NO')
        
        else:
            print('NO')

else:
    print('NO')

