b=input()
c=[]
for letter in b:
    if letter not in c:
        c.append(letter)
    else:
        continue
if len(c)%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")