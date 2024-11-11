n=int(input())
l=list(map(int,input().split()))
s=set(l)
if(n==len(s)):
        print(0)
else:
        s=set()
        j=0
        for i in range(n):
            if(l[i] not in s):
                s.add(l[i])
            else:
                j=i
                break
        if(j==0):
            print(0)
        else:
            ans=0
            for i in range(j+1):
                s=set()
                for k in range(i):
                    if(l[k] not in s):
                        s.add(l[k])
                    else:
                        break
                for k in range(n-1,-1,-1):
                    if(l[k] not in s):
                        s.add(l[k])
                    else:
                        break
                ans=max(ans,len(s))
            print(n-ans)