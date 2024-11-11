def minmax(string):
  a=[int(i) for i in string]
  return min(a),max(a)
def fignia(a,n): 
  k=True
  for _ in range(n-1):
    if k==True:  
       l=minmax(str(a)) 
       t=l[0]*l[1]
       a=a+t
       if t==0:
           k=False
    else :
            break

  print(a)    
 
n=int(input())
massiv_tipo=[fignia(*(int(j) for j in input().split(' '))) for i in range(n)]