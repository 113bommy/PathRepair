for i in range(int(input())):
     a = int(input())
     b = list(map(int,input().split()))
     d = True
     f = []
     g = 0
     y = False
     for j in range(len(b)+1):
          for h in range(j+1,len(b)+1):
               c = b[j:h]
               if sum(c)%2==0:
                    d = False
                    if j==h:
                         print(1)
                         print(j+1)
                         y = True
                         break
                    else:
                         print(h-j)
                         for x in range(j,h):
                              print(x+1,end=" ")
                         y = True
                         print()
                         break
          if y:
               break
                    
     
     if d:
          print(-1)
