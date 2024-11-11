a,b,c=map(int,input().split())
for s in range(1,100):
  if a*s%b==c:
    print("YES")
    exit()
print("NO")