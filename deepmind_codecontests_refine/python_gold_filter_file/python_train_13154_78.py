a=input()
b=[]
for i in a:
    if i not in b:
        b.append(i)
if len(b)%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")