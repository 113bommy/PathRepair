try:
   for _ in range(int(input())):
      n,k1,k2=map(int,input().split())
      l1=[int(i) for i in input().split()][:k1]
      l2=[int(j) for j in input().split()][:k2]
      max1=max(l1)
      max2=max(l2)
      if max1>max2:
         print("YES")
      else:
         print("NO")
except Exception as e:
   print(e)