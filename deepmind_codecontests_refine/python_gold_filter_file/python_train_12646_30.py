n=int(input())
s=input()
s=s.lower()
t=len(set(s))
if(t==26):
    print("YES")
else:
    print("NO")