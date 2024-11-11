s=input()
l=[]
for i in range(1,len(s)-1,3):
    if s[i] not in l:
        l.append(s[i])
print(len(l))