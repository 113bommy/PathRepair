a = []
b = []
n = 0
m = 0

def Init():
   global a,b,n,m
   size = [int(x) for x in input().split(" ")]
   n = size[0]
   m = size[1]
   
   for i in range(n):
      x = []
      y = input()
      for char in y:
        
        if (char == 'f') : x.append(1)
        elif (char == 'a') : x.append(5)
        elif (char == 'c') : x.append(21)
        elif (char == 'e'): x.append(85)
        else :x.append(0)
      a.append(x)
   
     
def Calcu(x, y):
  s=a[x][y] + a[x][y+1] + a[x + 1][y] + a[x + 1][y + 1]
  if (s) == 112:
    return True
  else:
    return False  
def getResuilt():
  global a, b, n, m
  res=0
  for i in range(n-1):
      for j in range(m - 1):
          if (Calcu(i,j)):
            res += 1
  print(res)
  


if __name__ == "__main__":
  Init()
  getResuilt()
