for _ in range(int(input())):
    a=input()
    k=[]
    for i in a:
        k.append(i)
    s=set(k)
    if len(s)!=len(k):
        print('No')
    else:
        k.sort()
        i=0
        while i<len(k)-1:
            if (ord(k[i+1])-ord(k[i]))!=1:
                print('No')
                break
            i=i+1
        else:
            print('Yes')