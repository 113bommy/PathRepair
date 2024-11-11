n=int(input())
s=str(input())
s2=s.lower()
aset=set(s2)
if len(aset)>=26:
    print("YES")
else:
    print("NO")