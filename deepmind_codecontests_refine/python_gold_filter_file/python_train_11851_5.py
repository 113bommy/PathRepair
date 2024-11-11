import sys
N=int(input())
if N==3:
    print(2,5,63)
    sys.exit()
if N==4:
    print(2,5,20,63)
    sys.exit()
S=[]
L=[0,2,3,4]
for i in range(1,30001):
    j=i%6
    if j in L:
        S.append(i)
    if len(S)==N-1:
        break
s=sum(S)
def f(L):
    return print(' '.join(map(str,L)))
if s%6==0:
    f(S+[30000])
elif s%6==2:
    f(S+[29998])
elif s%6==3:
    f(S+[29997])
elif s%6==5:
    f(S[1:]+[29997,30000])
#print(len(S),s%6)