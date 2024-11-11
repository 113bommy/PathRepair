s=input()
a=s.count('1')
b=s.count('2')
c=s.count('3')
if b==0 and c==0:
    for i in range(0,a-1):
        print("1+",end="")
    print("1",end="")
elif a==0 and c==0:
    for i in range(0,b-1):
        print("2+",end="")
    print("2",end="")
elif a==0 and b==0:
    for i in range(0,c-1):
        print("3+",end="")
    print("3",end="")
else:
    for i in range(0,a):
        print("1+",end="")
    for i in range(0,b-1):
        print("2+",end="")
    if b!=0:
        print("2",end="")
    if c!=0 and b!=0:
        print("+",end="")
    for i in range(0,c-1):
        print("3+",end="")
    if c!=0:
        print("3",end="")
    
    




