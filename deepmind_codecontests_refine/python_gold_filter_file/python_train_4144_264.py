a,b=map(int,input().split())
 
n=0
while (a-1)*n+1 < b:
  n+=1
  
print(n)