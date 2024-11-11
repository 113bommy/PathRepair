n=int(input())
s=list(input())

if n==1:
    print("1")
    l=''.join(map(str, s))
    print(l)
elif s.count("1")!=s.count("0"):
    print("1")
    l=''.join(map(str,s))
    print(l)
else:
    s1=""
    s2=""
    for i in range(0,n-1):
        s1=s1+s[i]
    for i in range(n-1,n):
        s2+=s[i]
    print("2")
    print(s1,s2)
    
