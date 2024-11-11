n=input()
s=""
flag=True
for i in range(len(n)):
    if(int(n[i])%8==0):
        flag=False
        s=n[i]
for i in range(len(n)):
    for j in range(i+1,len(n)):
        if(int(n[i]+n[j])%8==0):
            flag=False
            s=n[i]+n[j]
for i in range(len(n)):
    for j in range(i+1,len(n)):
        for k in range(j+1,len(n)):
            if(int(n[i]+n[j]+n[k])%8==0):
                s=n[i]+n[j]+n[k]
                flag=False
if(flag):print("NO")
else:
    print("YES")
    print(int(s))