n=int(input())
s=input()
s=s.lower()
s=list(set(s))
if(len(s)!=26):
    print("NO")
else:
    print("YES")