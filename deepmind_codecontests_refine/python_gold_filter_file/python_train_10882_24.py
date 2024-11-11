I=lambda:map(int,input().split())
n,m=I()
a=set(I())
b=[]
i=1
while i<=m:
    if i not in a:b.append(str(i));m-=i
    i+=1
print(len(b),'\n'+' '.join(b))