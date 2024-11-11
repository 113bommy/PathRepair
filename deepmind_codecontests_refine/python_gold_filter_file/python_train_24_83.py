import math

T = int(input())

lets = 'abcdefghijklmnopqrstuvwxyz'

key = {lets[i]:i for i in range(26)}

for i in range(T):
  n = int(input())
  #n,m = map(int, input().split())
  #a = input()
  a = list(map(int,input().split()))
  d = False
  if a[0] + a[1] <= a[-1]:
    print(1,2,n)
  else:
    print(-1)