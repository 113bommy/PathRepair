N = int(input())
A = list(map(int, input().split()))
odd = [a for a in A if a%2]

if len(odd)%2:
  print('NO')
else:
  print('YES')