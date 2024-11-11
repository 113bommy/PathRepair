# -*- coding: utf-8 -*-

N = int(input())
A = [input() for _ in range(N)]

def count(a):
  if '.' in a:
    c = a.split('.')
    n = int(c[0]+c[1])
    count2 = count5 = 9 - len(c[1])
  else:
    n = int(a)
    count2 = count5 = 9
  while n%2==0 and count2<18:
    n //= 2
    count2 += 1
  while n%5==0 and count5<18:
    n //= 5
    count5 += 1
  return count2, count5

Z = [[0 for _ in range(19)] for _ in range(19)]
answer = 0
for a in A:
  c2, c5 = count(a)
  answer += Z[18-c2][18-c5]
  for i in range(c2+1):
    for j in range(c5+1):
      Z[i][j] += 1

print(answer)