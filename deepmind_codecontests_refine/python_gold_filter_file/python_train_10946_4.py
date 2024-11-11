s=input().split()
a=int(s[0])
b=int(s[1])
c=int(s[2])
s[0]=a//3
s[1]=b//2
s[2]=c//2
s.sort()
a=a-s[0]*3
b=b-s[0]*2
c=c-s[0]*2
a1=[1, 4, 0]
b1=[2, 6]
c1=[3,5]
max=0

for i in range(0, 7):
    result=0
    at=a
    bt=b
    ct=c
    day=i
    while(at>=0 and bt>=0 and ct>=0 and at+bt+ct>0):
        if(day in a1 and at!=0):
            at-=1
        elif(day in b1 and bt!=0):
            bt-=1
        elif(day in c1 and ct!=0):
            ct-=1
        else:
            break
        result+=1
        day+=1
        day=day%7
    if(max<result):
        max=result
        kun=i
print(max+s[0]*7)
#print(kun)

