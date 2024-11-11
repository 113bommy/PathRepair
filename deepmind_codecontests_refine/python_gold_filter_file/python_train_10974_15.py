n=int(input())
s1=""
for i in range(1,n+1):
    if i%2:
        s1+="C"
    else:
        s1+="."
s2=s1.replace("C.", ".C")
s2=s2.replace("CC", "C.")
if n%2:
    print((int(n/2+1))**2 + (int(n/2))**2)
else:
    print(int(n**2/2))
for i in range(1,n+1):
    if i%2:
        print(s1)
    else:
        print(s2)