n=int(input())
s1=input()
s2=input()
s3=input()
a1,a2,a3,L=[0]*256,[0]*256,[0]*256,len(s1)
for i in range(L):
    a1[ord(s1[i])]+=1
    a2[ord(s2[i])]+=1
    a3[ord(s3[i])]+=1
m1,m2,m3=max(a1),max(a2),max(a3)

L1,L2,L3=L,L,L
if n==1 and m1==L: L1=L-1
if n==1 and m2==L: L2=L-1
if n==1 and m3==L: L3=L-1

m1,m2,m3=min(m1+n,L1),min(m2+n,L2),min(m3+n,L3)
if m1>m2 and m1>m3:
    print("Kuro")
else:
    if m2>m1 and m2>m3:
        print("Shiro")
    else:
        if m3>m1 and m3>m2:
            print("Katie")
        else:
            print("Draw")
