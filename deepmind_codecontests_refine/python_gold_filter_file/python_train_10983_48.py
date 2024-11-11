line=input()
u=l=0
for a in line:
    
    if(a.isupper()==True):
        u=u+1
    elif(a.islower()==True):
        l=l+1
if(u>l):
    print(line.upper())
    
elif(l>=u):
    print(line.lower())
