a , b = map(int , input().split())
if a in [1,3,5,7,8,10,12]:
    if b>=6:
        print(6)
    else:
        print(5)
elif a in [4,6,9,11]:
    if b==7:
        print(6)
    else:
        print(5)
else:
    if b==1:
        print(4)
    else:
        print(5)
