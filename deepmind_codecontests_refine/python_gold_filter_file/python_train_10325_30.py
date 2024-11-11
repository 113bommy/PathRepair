n=int(input())
a=list(map(int,input().split()))
sa=sum(a)
ma=max(a)
if sa%2:
  print("NO")
elif ma>sa-ma:
  print("NO")
else:
  print("YES")