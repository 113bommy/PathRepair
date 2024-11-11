# -*- coding: utf-8 -*-
import collections
import math

N, P = map(int, input().split())

insuList=[]
warukazu = 2
while (warukazu <= math.sqrt(P) +1):
  if P % warukazu == 0:
    P = P / warukazu
    insuList.append(warukazu)
  else:
    warukazu+=1
insuList.append(P)

ans=1
c=collections.Counter(insuList)
for key in c.keys():
  while c[key] >= N:
    ans=ans*key
    c[key] -= N

print(int(ans))