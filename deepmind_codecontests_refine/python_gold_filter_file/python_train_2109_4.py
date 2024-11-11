t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    l=list(s)
    i=len(l)-1
    l1=[]
    while i>=0:
        if l[i]=='1':
            l1.append(l[i])
        else:
            break
        i=i-1
    i=0
    l2=[]
    while i<len(l):
        if l[i]=='0':
            l2.append('0')
        else:
            break
        i=i+1
    val=0
    for j in range(len(l)-1):
        if l[j]=='1' and l[j+1]=='0':
            val=1
            break
    if val==1:
        l2.append('0')
    print("".join(l2),end="")
    print("".join(l1))