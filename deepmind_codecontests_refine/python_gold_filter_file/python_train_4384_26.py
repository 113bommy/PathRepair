a = list(map(int,input().split()))
w = a[0]
h = a[1]
k = a[2]
p1 = (2 *(w + h)) - 4
p2 = 0
w1 = 0
h1 = 0
if k <= (min(w,h) + 1) // 4:
     for i in range(2,k + 1):
          w1 = w - 4 * (i-1)
          h1 = h - 4 * (i-1)
          p2 += (2 *(w1 + h1)) - 4   
     print(p1 + p2)
    
        
    