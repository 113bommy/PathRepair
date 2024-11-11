n=int(input())
l=input()
m=input()
s=[]
t=[]
for i in range(len(l)):
    s.append(l[i])
    t.append(m[i])
a=[0]*26
b=[0]*26
for i in range(len(s)):
    a[ord(s[i])-97]+=1
    b[ord(t[i])-97]+=1
for i in range(len(a)):
    if a[i]!=b[i]:
        print(-1)
        break
else:
    if s==t:
        print(0)
    else:
        x=[]
        for i in range(len(s)):
            if s[i]!=t[i]:
                for j in range(i,len(s)):
                    if s[j]==t[i]:
                        for k in range(j-i):
                            x.append(j-1-k)
                            s[j-k]=s[j-k-1]
                        break
                            
        print(len(x))
        for i in range(len(x)):
            print(x[i]+1,end=' ')