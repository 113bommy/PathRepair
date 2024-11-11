c=""
t=0
a=input(),input()
for i in range(len(a[0])):
    if a[0][i]!=a[1][i]:
        c+=a[t%2][i]
        t+=1
    else:
        c+=str(int(not int(a[0][i])))
print(c if not(t%2) else "impossible")