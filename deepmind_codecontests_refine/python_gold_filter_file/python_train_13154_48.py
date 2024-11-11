s=input()
u=[]
for i in s:
    if i not in u:
        u.append(i)
if len(u)%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
