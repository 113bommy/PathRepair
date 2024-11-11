x=input()
p=[]
for i in x:
    if i not in p:
        p.append(i)
if len(p)%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")