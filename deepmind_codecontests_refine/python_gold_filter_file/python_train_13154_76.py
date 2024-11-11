s=input()
li=[]
for i in s:
    if i not in li:
        li.append(i)
if len(li)%2==0:
    print('CHAT WITH HER!')
else:
    print('IGNORE HIM!')