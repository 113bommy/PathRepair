n=input()
s=0
for i in n:
    s+=int(i)
print(['No','Yes'][int(n)%s==0])
