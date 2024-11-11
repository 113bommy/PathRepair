n=int(input())
a=[]
cnt=0
ans=""
s=0
if n>=6:
    for j in range(2,30001):
        if j%6==0 or j%6==2 or j%6==3 or j%6==4:
            a.append(j)
            cnt+=1
            s+=j
            if cnt==n:
                if s%6==0:
                    for i in range(n-1):
                        ans+=str(a[i])+" "
                    ans+=str(a[-1])
                    print(ans)
                elif s%6==2:
                    a[4]=30000
                    for i in range(n-1):
                        ans+=str(a[i])+" "
                    ans+=str(a[-1])
                    print(ans)
                elif s%6==3:
                    a[5]=30000
                    for i in range(n-1):
                        ans+=str(a[i])+" "
                    ans+=str(a[-1])
                    print(ans)
                else:
                    a[5]=29998
                    for i in range(n-1):
                        ans+=str(a[i])+" "
                    ans+=str(a[-1])
                    print(ans)
elif n==3:
    print(str(2)+" "+str(5)+" "+str(63))
elif n==4:
    print(str(2)+" "+str(5)+" "+str(20)+" "+str(63))
else:
    print(str(2)+" "+str(5)+" "+str(20)+" "+str(30)+" "+str(63))