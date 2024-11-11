n=input();n=int(n);
ans=0;prev=1;
for i in range(1,11):
     if(n>=(10**i)):
         ans+=(10**i-prev)*i
         prev=10**i
     else:
         if(n<10): 
             ans=n
             break
         else:
             ans+=(n-prev+1)*i
             break
print(ans)             
         