s=input()
if len(s)<=20:
    print("1"+" "+str(len(s)))
    print(s)
else:
    l=len(s)
    a=l//20
    if l%20>0:
        a+=1
    b=l//a
    if l%a>0:
        b+=1
    k=l%a
    if k!=0:
        j=0
        print(str(a)+" "+str(b))
        for i in range(k):
            print(s[j:j+b])
            j+=b
        for i in range(a-k):
            print(s[j:j+b-1]+"*")
            j+=b-1
    else:
        j = 0
        print(str(a) + " " + str(b))
        for i in range(a):
            print(s[j:j + b])
            j += b





