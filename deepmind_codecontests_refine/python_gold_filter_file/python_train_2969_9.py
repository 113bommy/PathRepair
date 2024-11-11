a,b,c=map(str,input().split())


if c=='month' and int(a)<=29:
    print(12)
elif c=='month' and int(a)==30:
    print(11)
elif c=='month' and int(a)==31:
    print(7)
elif c=='week' and a=='5':
    print(53)
elif c=='week' and a=='6':
    print(53)
else:
    print(52)
    
