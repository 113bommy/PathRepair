s=input()
f=[]

for i in s:
    if i not in f:
        f.append(i)

if len(f)%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
