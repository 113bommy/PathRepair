n,k=map(int, input().split())
s=input()
a=s
s=[]
for i in range(len(a)):
    s.append(a[i])
#print(*s)
prev=0
alphs=[]
ans=0
for i in range(k):
    alphs.append(chr(ord('A')+i))
#print(alphs)
if k==2:
    f=[]
    sec=[]
    t=0
    for i in range(n):
        f.append(chr(ord('A')+t))
        sec.append(chr(ord('A')+(t+1)%2))
        t^=1
    #print(f,sec)
    ans1=0
    ans2=0
    for i in range(n):
        if s[i]!=f[i]:
            ans1+=1
        if s[i]!=sec[i]:
            ans2+=1
    if ans1<=ans2:
        print(ans1)
        for i in f:
            print(i,end='')
    else:
        print(ans2)
        for i in sec:
            print(i,end='')
else:
    for i in range(1,n):
        #print(prev, i)
        if s[i]!=s[prev]:
            if i-prev>1:
                #print('YES')
                if (i-prev)%2:
                    ans+=(i-prev)//2
                    t=0
                    put=''
                    for j in alphs:
                        if j!=s[prev]:
                            put=j
                            break
                    for j in range(prev, i):
                        if t%2:
                            s[j]=put
                        t+=1

                else:
                    end=''
                    other=''
                    for j in alphs:
                        if j!=s[prev] and j!=s[i]:
                            end=j
                            break
                    for j in alphs:
                        if j!=s[prev] and j!=end:
                            other=j
                            break
                    s[i-1]=end
                    ans+=1
                    t=0
                    for j in range(i-2, prev-1, -1):
                        if t%2:
                            s[j]=other
                            ans+=1
                        t+=1
            prev=i
    i=n-1
    #print(s)
    #print(prev, i,alphs)
    for i in range(n-1,-1,-1):
        if s[i]!=s[n-1]:
            prev=i+1
            break
    i=n-1
    if i - prev>0:
        if (i - prev+1 ) % 2:
            ans += (i - prev+1 ) // 2
            t = 0
            put = ''
            for j in alphs:
                if j != s[i]:
                    put = j
                    break
            for j in range(prev, i+1):
                if t % 2:
                    s[j] = put
                t += 1

        else:
            other = ''
            for j in alphs:
                if j != s[prev]:
                    other = j
                    break
            t = 0
            for j in range(i, prev - 1, -1):
                if t % 2==0:
                    s[j] = other
                    ans+=1
                t += 1
    #print(s)
    print(ans)
    for i in s:
        print(i,end='')



