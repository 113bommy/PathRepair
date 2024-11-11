n=int(input())
s=sorted(input())
t=s[::n]*n
if sorted(t)==s:
    print("".join(t))
else:
    print("-1")






