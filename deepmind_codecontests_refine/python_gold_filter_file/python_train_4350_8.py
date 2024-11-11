n=int(input())
ans=''
check='abcdefghijklmnopqrstuvwxyz'
while n!=0:
  n-=1
  ans+=check[n%26]
  n//=26
print(ans[::-1])