t=int(input())
i=0
while i<t:
    s=input()
    s=list(s)
    s.append(1)
    s.append(1)
    n=len(s)
    ans=[]
    for x in range(n-2):
        if s[x]=='o' and s[x+1]=='n' and s[x+2]=='e':
            ans.append(x+1)
            s[x+1]=1
        elif s[x]=='t' and s[x+1]=='w' and s[x+2]=='o':
            if s[x+3]=='n' and s[x+4]=='e':
                ans.append(x+2)
                s[x+2]=1
            else:
                ans.append(x+1)
                s[x+1]=1
    print(len(ans))
    for x in ans:
        print(x+1,end=" ")
    print()


    i=i+1
