arr = [1,7,9,10,11,13,14,15,16,17,18,19]
x = int(input())
if(x<20):
    if x in arr:
        print('NO')
    else:
        print('YES')
elif(x>=20 and x<=29):
    print('NO')
elif(x>=70 and x<=79):
    print('NO')
elif(x>90):
    print('NO')
else:
    if(x%10 in [1,7,9]):
        print('NO')
    else:
        print('YES')