n = int(input())
a = [int(i) for i in input().split()]
 
ans = 'YES'
if sum(a)%2 != 0:
  ans = 'NO'
  
print(ans)