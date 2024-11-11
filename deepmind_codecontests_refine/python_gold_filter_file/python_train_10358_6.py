n=list(map(int,input().split()))
s=input()
n.sort()
if s=="+ + +":
    print(sum(n))
elif s=="+ + *":
    print(n[0]*sum(n[1:4]))
elif s=="+ * +" or s=="* + +":
    print(n[2]+n[3]+(n[0]*n[1]))
elif s=="* * *":
    print(n[0]*n[1]*n[2]*n[3])
elif s=="* * +":
    print((n[0]*n[3])+(n[1]*n[2]))
elif s=="* + *":
    print(n[0]*(n[3]+(n[1]*n[2])))
elif s=="+ * *":
    print((n[0]*n[1])*(n[2]+n[3]))
