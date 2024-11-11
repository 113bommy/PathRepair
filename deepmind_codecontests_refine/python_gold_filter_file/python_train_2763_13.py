input()
f = set(input())
if ('0' in f) and not(f.isdisjoint(set({'1', '2', '3'}))):
    print("YES")
else:
    if (('1' in f) and ('9' in f)) or (('3' in f) and ('7' in f)) or ():
        print("YES")
    else:
        if set({'2', '4', '6', '8'}).issubset(f) and not f.isdisjoint(set({'7','9'})): print("YES")
        else:
            if set({'3', '4', '9'}).issubset(f) or set({'2', '9', '7'}).issubset(f) or set({'1', '7', '6'}).issubset(f): print("YES")
            else:
                if (('7' in f) and ('6' in f) and ('2' in f)) or (('9' in f) and ('4' in f) and ('2' in f)): print("YES")
                else: print("NO")
