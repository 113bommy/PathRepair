a=input();
if len(a)>1:
    print(a.swapcase() if a[1:].isupper() else a)
else:
    print(a.swapcase())
