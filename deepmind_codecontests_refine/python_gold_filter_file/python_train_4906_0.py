n = int(input())
T = input().split(' ')
for i in range(n):
    T[i]=int(T[i])
L=[]
M=[]
t=0
ip=0
IP=[]
for i in range(n):
    if T[i]>=2:
        L.append(i+1)
        M.append(T[i])
        t+=T[i]
    else:
        ip+=1
        IP.append(i+1)
if t-(2*len(L)-2)<ip:
    print("NO")
else:
    for i in range(1, len(L)-1):
        M[i]-=2
    if len(L)>=2:
        M[0]-=1
        M[-1]-=1
    print("YES",end=' ')
    if ip==0:
        print(len(L)-1)
    elif ip==1:
        print(len(L))
    else:
        print(len(L)+1)
    print(len(L)-1+ip)
    if ip>=1:
        print(IP[0], end=' ')
        print(L[0])
        M[0]-=1
    if ip>=2:
        print(IP[-1], end=' ')
        print(L[-1])
        M[-1]-=1
    k=1
    ind=0
    while k < ip-1:
        if M[ind]==0:
            ind+=1
        else:
            print(IP[k], end=' ')
            print(L[ind])
            M[ind]-=1
            k+=1
    for i in range(len(L)-1):
        print(L[i], end=' ')
        print(L[i+1])
