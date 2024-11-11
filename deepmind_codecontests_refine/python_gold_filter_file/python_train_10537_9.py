for t in range(int(input())):
    s=input()
    z=input()
    c=[]
    a=[]
    plus=0
    for i in z:
        c.append(i)
        plus+=1
    count=0
    for i in s:
        a.append(i)
        count+=1
    b=[[0 for i in range(26)] for j in range(count+1)]
    alpha=[9999999 for i in range(26)]
    for i in range(count):
        alpha[ord(a[i])-97]=min(alpha[ord(a[i])-97],i)
    i=count-1
    while(i>=1):
        b[i][ord(a[i])-97]=i
        b[i-1]=b[i][::]
        i-=1
    add=1
    one=alpha[ord(c[0])-97]
    if(one==9999999):
        print(-1)
        continue
    i=0
    while True:
        i+=1
        if(i==plus):
            flag=1
            break
        two=ord(c[i])-97
        if(b[one+1][two]==0):
            add+=1
            one=alpha[ord(c[i])-97]
            if(one==9999999):
                flag=-1
                break
        else:
            one=b[one+1][two]
    if(flag==-1):
        print(-1)
    else:
        print(add)