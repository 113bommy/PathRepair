name=str(input())
alist=[]
l=len(name)
for i in range(l):
    if name[i] in alist:
        alist=alist
    if not name[i] in alist:
        alist.append(name[i])
num=len(alist)
if num%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")