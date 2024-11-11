x="abcdefghijklmnopqrstuvwxyz"
y=input()
co=0
for i in x:
    if i in y:
       co+=1
if co%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")