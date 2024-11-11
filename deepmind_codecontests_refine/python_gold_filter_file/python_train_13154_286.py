x=input()
n=[]
for i in x:
    if i not in n:
        n.append(i)
if(len(n)%2==0):
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")