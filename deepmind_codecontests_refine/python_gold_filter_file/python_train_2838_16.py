t=int(input())
for i in range(t):
   a,b,c=map(int,input().split())
   if((a==b)and(c<=b)):
       print("YES",end='\n')
       print(a,c,c,end='\n')
   elif((b==c)and(a<=b)):
        print("YES",end='\n')
        print(b,a,a,end='\n')
   elif((a==c)and(b<=a)):
        print("YES",end='\n')
        print(a,b,b,end='\n')
   else:
        print("NO",end='\n')