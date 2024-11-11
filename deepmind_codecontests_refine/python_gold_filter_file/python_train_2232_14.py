a,b,c,d=map(int,input().split())
s=input()
cal=0
for i in range(len(s)):
    if int(s[i])==1:
        cal += a
    elif int(s[i])==2:
        cal += b
    elif int(s[i])==3:
        cal += c
    elif int(s[i])==4:
        cal += d
print(cal)