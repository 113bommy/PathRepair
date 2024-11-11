from collections import Counter
n=int(input())
s=str(input())
s1=str(input())
s2=str(input())
t=len(s)
l=Counter(s)
l1=Counter(s1)
l2=Counter(s2)
k=max(l.values())
k1=max(l1.values())
k2=max(l2.values())
#print(k,k1,k2)
if n+k>=t:
    if k==t and n!=0:
        if n==1:
            k=k-1
        else:
            k=t
    else:
        k=t
else:
    k=k+n
if n+k1>=t:
    if k1==t and n!=0:
        if n==1:
            k1=k1-1
        else:
            k1=t
    else:
        k1=t
            
else:
    k1=k1+n
if k2+n>=t:
    if k2==t and n!=0:
        if n==1:
            k2=t-1
        else:
            k2=k2
    else:
        k2=t
else:
    k2=k2+n
#print(k,k1,k2)
if k>k1 and k>k2:
    print("Kuro")
elif k>=k1 and k>=k2:
    print("Draw")
elif k1>k and k1>k2:
    print("Shiro")
elif k1>=k and k1>=k2:
    print("Draw")
elif k2>k and k2>k1:
    print("Katie")
elif k2>=k and k2>=k1:
    print("Draw")
#print(t)
#for i in range(n):
    