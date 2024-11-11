b,s=-1e10,1e10
for _ in range(int(input())):
 r=int(input())
 b,s=max(b,r-s),min(s,r)
print(b)
