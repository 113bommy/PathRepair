import sys,os,io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

for _ in range (int(input())):
    s = list(input())
    s = [int(i) for i in s]
    n = len(s)
    o = -1
    e = -1
    for i in range (len(s)):
        if s[i]%2==1 and o==-1:
            o = i
        elif s[i]%2==0 and e==-1:
            e = i
        if o!=-1 and e!=-1:
            break
    curr = 0
    ans = []
    if o==-1 or e==-1:
        ans = s[:]
    else:
        while(o<n and e<n):
            if s[o]<=s[e]:
                ans.append(s[o])
                o+=1
                while(o<n):
                    if s[o]%2==0:
                        o+=1
                    else:
                        break
            else:
                ans.append(s[e])
                e+=1
                while(e<n):
                    if s[e]%2==1:
                        e+=1
                    else:
                        break
        if o<n:
            for i in range (o,n):
                if s[i]%2==1:
                    ans.append(s[i])
        else:
            for i in range (e,n):
                if s[i]%2==0:
                    ans.append(s[i])
    for i in ans:
        print(i,end="")
    print()