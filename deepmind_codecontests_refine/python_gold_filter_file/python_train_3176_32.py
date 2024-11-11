s=input()
s=s.split()
n=int(s[0])
k=int(s[1])
a=10**(n-1)
x=a+(k-a%k)
if k>=10**n :
    print("-1")
else :
    print(x)