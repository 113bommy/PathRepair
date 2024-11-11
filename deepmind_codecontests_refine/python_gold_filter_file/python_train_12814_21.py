n=int(input())
s1=input()
s2=input()
ans = []
b=0
for i in range(n):
   # print(s2[i] + s1[i])
    if(s1[i]!=s2[i]):
        c=0
        for j in range(n-1,i,-1):
            #print(s2[i]+s1[j])
            if(s2[i] == s1[j]):
                s=list(s1)
                t = s[j-1]
                s[j-1] = s[j]
                s[j] = t
                s1 = s
                ans.append(j)
                c+=1
        if(c==0 and b==0):
            print(-1)
            b=1

if (b==0):
    print(len(ans))
    print(*ans)


