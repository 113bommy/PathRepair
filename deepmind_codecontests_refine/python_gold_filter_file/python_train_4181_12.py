inp=input()
n=int(inp)
for i in range(n):
    s=input()
    st=''.join(sorted(s))
    a=ord(st[0])-96
    b=ord(st[len(st)-1])-96
    if b==(a+len(st)-1) and len(set(st))==len(st):
        print("YES\n")
    else:
        print("NO\n")



