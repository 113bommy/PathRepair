import sys
input=sys.stdin.readline

N,M=[int(n) for n in input().split()]
lis=[[i]+[int(n) for n in input().split()] for i in range(M)]
#print(lis)
l_2=sorted(lis, key=lambda x: x[2])
dic={}
for k,i,j in l_2:
    dic[i]=dic.get(i,0)+1
    lis[k]='{:0=6}{:0=6}'.format(i,dic[i])
for i in lis:print(i)