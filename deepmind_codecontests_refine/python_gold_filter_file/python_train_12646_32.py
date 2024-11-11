n=int(input())
s=input()
x=s.lower()
y=len(set(x))
if y==26:
    print("YES")
else:
    print("NO")