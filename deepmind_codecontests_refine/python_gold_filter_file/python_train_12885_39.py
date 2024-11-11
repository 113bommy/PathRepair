n=input()
t=input()
c=0
for i in range(len(n)):
    if n[i]!=t[i]:
        c+=1
print(c)