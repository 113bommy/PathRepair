from math import*
m=list(map(int,input().split()))
w=list(map(int,input().split()))
hs=0;hu=0;o=0;t=0
hs,hu=map(int,input().split())
for i in range(5):
    x=500*(i+1)
    o+=max(0.3*x,(1-m[i]/250)*x-50*w[i])
print(int(o+100*hs-50*hu))
