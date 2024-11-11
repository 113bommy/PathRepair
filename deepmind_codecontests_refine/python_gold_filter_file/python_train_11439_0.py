while 1:
 n=int(input())
 if n==0:break;
 a=[]
 for i in range(n):
  a+=[list(map(int,input().split()))]
  a[i]+=[sum(a[i])]
  for s in a[i]:print("%5d"%s,end='')
  print()
 for c in zip(*a):print("%5d"%sum(c),end='')
 print()
