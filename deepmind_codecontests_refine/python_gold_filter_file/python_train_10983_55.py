s=input()
l=0;u=0
for i in s:
    if ord(i)>=65 and ord(i)<97:
        u+=1
    if ord(i)>=97:
        l+=1
if(u==l):
    print(s.lower())
elif(u>l):
    print(s.upper())
else:
    print(s.lower())
