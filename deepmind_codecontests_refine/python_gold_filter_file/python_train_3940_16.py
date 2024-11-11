n= int( input())
k = int( input())
 
a = 1
for i in range(n):
  a = min(a+k, a*2)  
print(a)