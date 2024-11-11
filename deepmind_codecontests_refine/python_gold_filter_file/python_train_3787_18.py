n,t=input().split(" ")
s=input()
ns=""
for i in range(int(t)):
    j=0
    while j<=int(n)-1:
        if (j<int(n)-1) and (s[j]=="B" and s[j+1]=="G"):
            ns=ns+s[j+1]+s[j]
            j+=1
        else:
            ns=ns+s[j]
        j+=1
    s=ns
    ns=""
print(s)       