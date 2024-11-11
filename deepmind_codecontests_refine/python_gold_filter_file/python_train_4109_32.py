a=int(input())
b=int(input())
c=int(input())
if a!=1 and b!=1 and c!=1 :
    print(a*b*c)
elif a==1 and b==1 and c==1:
    print(a+b+c)
elif a==1 and b!=1 and c!=1:
    print((a+b)*c)
elif a!=1 and b==1 and c!=1:
    print(max((a+b*c),((a+b)*c),(a*b+c),(a*(b+c))))
elif a!=1 and b!=1 and c==1:
    print(a*(b+c))
elif a==1 and b==1 and c!=1:
    print((a+b)*c)
elif a!=1 and b==1 and c==1:
    print(a*(b+c))
elif a==1 and b!=1 and c==1:
    print(a+b+c)