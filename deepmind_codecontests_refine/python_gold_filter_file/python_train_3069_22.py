arr=[input( ) for i in range(8)]
w,b=0,0
for i in range(8):
    for j in range(8):
        x = arr[i][j]
        if x =='Q' :w+=9
        elif x =='R':w+=5
        elif x =='B' or x=='N':w+=3
        elif x=='P' :w+=1
        if x =='q' :b+=9
        elif x =='r':b+=5
        elif x =='b' or x=='n':b+=3
        elif x == 'p': b += 1
if (w>b):print('White')
elif (w==b):print('Draw')
else : print('Black')