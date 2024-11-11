a=list(input())
s=[] 
c=0
for i in range(0,len(a)):
    if a[i] not in s:
        s.append(a[i])
l=(len(s))
if(l%2==0):
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")