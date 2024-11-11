s=input()
d=[]
for i in s:
    if i not in d:
        d.append(i)

if len(d)%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
