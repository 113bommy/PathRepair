t=0
x=input()
for i in x:
    if i.islower():
        t=t-1
    else:
        t=t+1
if t<=0:
    print(x.lower())
else:
    print(x.upper())