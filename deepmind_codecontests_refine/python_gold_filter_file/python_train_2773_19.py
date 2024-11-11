x = int(input())
s = input()
if(s[0]=="0"):
    h = int(s[1])
else:
    h = int(s[0])*10 + int(s[1])
if(s[3]=="0"):
    m=int(s[4])
else:
    m = int(s[3])*10 + int(s[4])

#print(h,m)

k=0

while(h//10 != 7 and h%10!=7 and m//10 != 7 and m%10!=7):
    m=m-x
    if(m<0):
        a=m
        m=60 + a
        h=h-1
        if(h<0):
            h=23
    k=k+1
    #print(h,m)

print(k)
