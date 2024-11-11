s=input()
s=s[1:(len(s)-1)]
u=[]
for i in range(0,len(s),3):
    u=u+[s[i]]
u=set(u)
print(len(u))
