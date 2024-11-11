a1,a2,a3,a4=map(str,input().split())
l=list(input())
c=0
for i in range(len(l)):
    if l[i]=="1":
        c+=int(a1)
    elif l[i]=="2":
        c+=int(a2)
    elif l[i]=="3":
        c+=int(a3)
    elif l[i]=="4":
        c+=int(a4)
print(c)
c=0