st1 = input()
st2 = input()
l1 = len(st1)
l2 = len(st2)
if(l1 > l2):
    print(l1)
elif(l2 > l1):
    print(l2)
else:
    if(st1 == st2):
        print(-1)
    else:
        print(l1)
        