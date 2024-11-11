m,d = map(int,input().split())

if m in [1,3,5,7,8,10,12]:
    print(6 if d in [6,7] else 5)
elif m in[4,6,9,11]:
    print(6 if d is 7 else 5)
else:
    print(4 if d is 1 else 5)