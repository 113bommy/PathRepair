class BIT():
    def __init__(self,n):
        self.BIT=[0]*(n+1)
        self.num=n

    def query(self,idx):
        res_sum = 0
        while idx > 0:
            res_sum += self.BIT[idx]
            idx -= idx&(-idx)
        return res_sum

    #Ai += x O(logN)
    def update(self,idx,x):
        while idx <= self.num:
            self.BIT[idx] += x
            idx += idx&(-idx)
        return

def comp(L):
    S=list(set(L))
    S.sort()
    return {i:e for e,i in enumerate(S)}

import sys,random

input=sys.stdin.readline

N=int(input())
A=[0]*N;B=[0]*N;C=[0]*N
for i in range(N):
    A[i],B[i],C[i]=map(int,input().split())

line=[(A[i]/B[i],i) for i in range(N)]
line.sort()
line=[line[i][1] for i in range(N)]

line2=[(B[i]/A[i],i) for i in range(N)]
line2.sort()
line2=[line2[i][1] for i in range(N)]

def cond(n):
    tempC=[C[i]-n*A[i] for i in range(N)]
    data=[tempC[i]/B[i] for i in range(N)]
    data=comp(data)
    bit=BIT(len(data))
    res=0
    for i in range(N):
        id2=data[tempC[line[i]]/B[line[i]]]
        res+=i-bit.query(id2)
        bit.update(id2+1,1)
    num=N*(N-1)//2
    return res>=(num+1)//2

def cond2(n):
    tempC=[C[i]-n*B[i] for i in range(N)]
    data=[tempC[i]/A[i] for i in range(N)]
    data=comp(data)
    bit=BIT(len(data))
    res=0
    for i in range(N):
        id2=data[tempC[line2[i]]/A[line2[i]]]
        res+=i-bit.query(id2)
        bit.update(id2+1,1)
    num=N*(N-1)//2
    return res>=(num+1)//2

start=-2*10**8
end=2*10**8
count=0
while end-start>10**-9:
    count+=1
    test=(end+start)/2
    if cond(test):
        end=test
    else:
        start=test
    if (end-start)*10**9<min(abs(start),abs(end)):
        break

start2=-2*10**8
end2=2*10**8
while end2-start2>10**-9:
    test=(end2+start2)/2
    count+=1
    if cond2(test):
        end2=test
    else:
        start2=test
    if (end2-start2)*10**9<min(abs(start2),abs(end2)):
        break

print(end,end2)
#print(count)
