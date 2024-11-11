a=input()
if len(a)==2:
    print(0)
else:
    s=a[1:-1].split(', ')
    a=set(s)
    print(len(a))