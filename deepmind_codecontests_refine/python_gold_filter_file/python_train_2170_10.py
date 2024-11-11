N = int(input())
A = [int(i) for i in input().split()]

ans = 3**N
tmp = 1
for a in A:
  if a%2==0:
    tmp *= 2
print(ans - tmp) 
