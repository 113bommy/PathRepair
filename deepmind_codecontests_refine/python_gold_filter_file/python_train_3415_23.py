n,l = map(int, input().split())

ans=l*n-n+(1+n)*n//2
if 0<l:
  ans=ans-l
elif l < 1-n:
  ans=ans-(l+n-1)

print(ans)  
