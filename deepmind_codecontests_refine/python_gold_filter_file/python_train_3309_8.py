s=input().split()
a,b=map(int,input().split())
u=input()
if s[0]==u:
    a-=1
else:
    b-=1
print(a,b)