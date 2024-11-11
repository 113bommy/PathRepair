l=input()
m=[]
for i in l:
    if i not in m:
        m.append(i)
if(len(m)%2==0):
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")