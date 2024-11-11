s=input()
l=[s[i] for i in range(len(s))]
ls=set(l)
x=len(ls)
if x%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")