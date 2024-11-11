a,b,c=map(int, input().split())
if a<b or a>b:
  ans=(2*min(a,b))+1+(2*c)
else:
  ans=(2*a)+(2*c)  
print(ans)  