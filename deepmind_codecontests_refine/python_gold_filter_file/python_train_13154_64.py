x=input()
z=[]
for i in x:
    if i not in z:
        z.append(i)
if len(z)%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
