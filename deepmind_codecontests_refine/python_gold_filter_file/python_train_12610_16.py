N=int(input())
S=[str(i) for i in input()]
L=[0,0,0]
for s in S:
    L[int(s)]+=1
num=N//3
T=S
a,b,c=L[0],L[1],L[2]
if a>=num and b>=num and c<=num:
    t=num-c
    s=a-num
    u=b-num
    i=N-1
    while t>0:
        if T[i]=='1' and u!=0:
            T[i]='2'
            t-=1
            u-=1
        elif T[i] == '0' and s != 0:
            T[i] = '2'
            t -= 1
            s -= 1
        i-=1

elif a>=num and b<=num and c<=num:
    t=num-c
    i=N-1
    while t>0:
        if T[i]=='0':
            T[i]='2'
            t-=1
        i-=1
    s=num-b
    while s>0:
        if T[i]=='0':
            T[i]='1'
            s-=1
        i-=1

elif a>=num and b<=num and c>=num:
    t=c-num
    i=0
    while t>0:
        if T[i]=='2':
            T[i]='1'
            t-=1
        i+=1
    i=N-1
    s=a-num
    while s>0:
        if T[i]=='0':
            T[i]='1'
            s-=1
        i-=1

elif a<=num and b>=num and c<=num:
    t=num-a
    i=0
    while t>0:
        if T[i]=='1':
            T[i]='0'
            t-=1
        i+=1
    i=N-1
    s=num-c
    while s>0:
        if T[i]=='1':
            T[i]='2'
            s-=1
        i-=1
elif a<=num and b<=num and c>=num:
    t=num-a
    i=0
    while t>0:
        if T[i]=='2':
            T[i]='0'
            t-=1
        i+=1
    s=num-b
    while s>0:
        if T[i]=='2':
            T[i]='1'
            s-=1
        i+=1
elif a<=num and b>=num and c>=num:
    t=num-a
    s=b-num
    u=c-num
    i=0
    while t>0:
        if T[i]=='2' and u!=0:
            T[i]='0'
            t-=1
            u-=1
        elif T[i]=='1'and s!=0:
            T[i]='0'
            t-=1
            s-=1
        i+=1
print(''.join(T))
#print(L)