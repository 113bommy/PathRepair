s=input()
if len(s)==2:
    print(0)
else:
    a=s[1:-1].split(', ')
    p=set(a)
    print(len(p))