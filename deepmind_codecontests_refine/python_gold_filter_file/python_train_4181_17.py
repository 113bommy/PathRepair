t=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
n=int(input())
for i in range(0,n):
    s=input()
    flag=1
    a={'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0,'k':0,'l':0,'m':0,'n':0,'o':0,'p':0,'q':0,'r':0,'s':0,'t':0,'u':0,'v':0,'w':0,'x':0,'y':0,'z':0}
    cnt=0
    #print(s)
    for j in s:
        if a[j]==1:
            flag=0
        else :
            a[j]=1
            cnt+=1
    flag1=0
    flag2=0
    for j in t:
        if a[j]==1 and flag2==0:
            flag2=1
            flag1=1
        elif a[j]==1 and flag2==1:
            flag1+=1
        elif a[j]==0 and flag2==1:
            flag2=2
    #print("a")
    if flag1!=cnt:
        flag=0
    #print(flag1)
    #print(cnt)
    if flag==1:
        print("Yes")
    else:
        print("No")