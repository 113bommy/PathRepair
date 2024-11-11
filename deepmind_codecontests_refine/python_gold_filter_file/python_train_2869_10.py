n=int(input())
set=[]
a=[]
b=[]
c=[]

new=[]
for _ in range(n):
    lis=input()
    set.append(lis)

for x in set:
    if len(x)<=10:
        new.append(x)
    elif len(x)>10:
        a=x[0]
        b=x[-1]
        c=len(x)-2
        ans=a+str(c)+b
        new.append(ans)

print('\n'.join(new))