n=int(input())
a=set(map(int,input().split()))
k=len(a)
#少なくともn-k枚減らす
if (n-k) % 2 == 0:
  print(k)
else:
  print(k-1)