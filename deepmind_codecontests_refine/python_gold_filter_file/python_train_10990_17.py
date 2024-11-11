m,d=map(int,input().split())
if m<8:
    if m%2!=0:
        if d<6:
             print('5')
        else:
             print('6')
    elif m==2:
        if d==1:
            print('4')
        else:
            print('5')
    else:
        if d<7:
             print('5')
        else:
             print('6')
else:
    if m%2!=0:
         if d<7:
              print('5')
         else:
              print('6')
    else: 
         if d<6:
              print('5')
         else:
              print('6')