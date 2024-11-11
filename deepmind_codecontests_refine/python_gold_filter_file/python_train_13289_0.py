from itertools import permutations as p
def ck(num,arr):
    for i in arr:
        if i>=num:
            print(i)
            return

x = input()
z = len(x)

if z == 1:
    print(47)
elif z == 2 :
    if int(x) <= 74:
        arr = [47,74]
        ck(int(x),arr)
    else:
        print(4477)
elif z == 3:
    print(4477)
elif z == 4:
    
    if int(x) <= 7744:
        arr4 = sorted([int("".join(i)) for i in p("4477")])
        ck(int(x),arr4)
    else:
        print(444777)
elif z == 5:
    print(444777)
elif z == 6:
    if int(x) <= 777444:
        
        arr6 = sorted([int("".join(i)) for i in p("444777")])
        ck(int(x),arr6)
    else:
        print(44447777)
elif z ==7:
    print(44447777)
elif z==8:
    if int(x)<=77774444:
        arr8 = sorted([int("".join(i)) for i in p("44447777")])
        ck(int(x),arr8)
    else:
        print(4444477777)
else:
    print(4444477777)
    
    

