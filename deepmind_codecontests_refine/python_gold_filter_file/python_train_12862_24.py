

"""
instagram : essipoortahmasb
telegram channel : essi_python

"""
i = input
a = []
n = int(i())
Flag = False
for j in range(n):
    a.append(i())

for j in range(n):
    if "OO" in a[j]:
        Flag = True
        a[j]=a[j].replace("OO","++",1)
        break
if Flag:
    print("YES")
    for j in a:
        print(j)
else:
    print("NO")
