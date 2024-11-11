n,k=map(int,input().split())
if n==1 :
    if k<=2:
      print("YES")
    else:
        print("NO")
elif k>=n:
      print("NO")
else:
      d=set()
      x=True
      for i in range(1,k+1):
            if n%i in d:
                  x= False
                  break
            else:
                  d.add(n%i)
      if x:
            print("YES")
      else:
            print("NO")