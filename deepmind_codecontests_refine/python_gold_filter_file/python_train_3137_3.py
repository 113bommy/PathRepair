n=int(input())
for i in range (n):
    c=input()
    if (c[0]*len(c))==c:
        print(-1)
    else:
        if c[::-1]!=c:
            print(c)
        else:
            l=[i for i in c]
            for i in range(1,len(l)//2+1):
                if l[0]!=l[i]:
                    x=l[0]
                    l[0]=l[i]
                    l[i]=x
            print("".join(l))