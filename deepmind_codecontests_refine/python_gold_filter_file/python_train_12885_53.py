s=input()
a=input()
c=0
for i in range(len(a)):
    if s[i]!=a[i]:
        c+=1
print(c)