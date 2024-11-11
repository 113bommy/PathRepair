for i in range(int(input())): 
     n,a,b = map(int,input().split())
     s = ""

     t = 0
     while len(s) < n:
          g = (a-b)+1
         
          for i in range(a):
               if g != 0:
                    g -= 1
                    s += "a"
               else:
                    s += chr(ord('b')+t)
                    t += 1
                    if ord('b')+t == 123:
                         t = 0
                    
               if len(s) == n:
                    break
     print(s)