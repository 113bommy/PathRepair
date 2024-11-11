s=input()
x,y=0,0
for i in s:
    if i.islower():
        x+=1
    elif x>0:
        y+=1
        x-=1
print(y)