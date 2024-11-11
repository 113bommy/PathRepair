l=list(map(int,input().split()))
l.sort()
l.reverse()
a,b,c,d=l
f=[[a,b,c],[a,c,d],[a,b,d],[b,c,d]]
x=True
for i in f:
      if i[0]-i[1]-i[2]<0:
            print("TRIANGLE")
            x=False
            break
if x :
      for i in f:
            if i[0]-i[1]-i[2]==0:
                  print("SEGMENT")
                  x=False
                  break
if x:
      print("IMPOSSIBLE")