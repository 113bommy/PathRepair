if __name__ =="__main__":
 for _ in range(int(input())):
  n,k = map(int,input().split())
  if n ==k:
   print(((-1)**n)*n)
  else:
   if n%2!=0:
    if k%2==0:
     sum = (k+1-n)//2
     print(sum)
    else:
     sum = (k-n+1)//2 -k
     print(sum)
   else:
    if k%2==0:
     sum = -1*(k-n)//2+k
     print(sum)
    else:
     sum = (-1*(k-n+1)//2)
     print(sum)
  
 
    
   
