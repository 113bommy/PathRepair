n=int(input())
s=input()
s=s.lower()
k=len(set(s))
if(k==26):
    print("YES")
else:
    print("NO")