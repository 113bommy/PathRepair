a=input()
if len(a)==2:
    print(0)
else:
    l=a[1:-1].split(', ')
    s=set(l)
    print(len(s))
