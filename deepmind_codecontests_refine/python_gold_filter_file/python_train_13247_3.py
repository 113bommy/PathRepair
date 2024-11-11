n = int(input())
s1 = list(input())
s2 = list(input())
o1 = s1.count('1')
o2 = s2.count('1')
ans1=ans2=0
if o1!=o2:
    print(-1)
else:
    zer=one=0
    for i in range(n):
        if s1[i]!=s2[i]:
            if s1[i]=='0':
                if(one>0):
                    one-=1
                else:
                    zer+=1
                    ans1 = max(ans1,zer)
            else:
                if(zer>0):
                    zer-=1
                else:
                    one+=1
                    ans2 = max(ans2,one)
    print(ans1+ans2)                    
