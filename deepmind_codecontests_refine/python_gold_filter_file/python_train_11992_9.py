n=int(input())
s=str(input().replace(''," "))
n1=s.count('n')
z1=s.count('z')
if n1>=1 and z1>=1:
    print(("1 "*n1),"0 "*z1)
elif n1==0 and z1>=1:
    print("0 "*z1)
elif n1>=1 and z1==0:
        print("1 "*n1)
