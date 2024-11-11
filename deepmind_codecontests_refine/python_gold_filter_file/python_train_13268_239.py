s=0
for _ in range(int(input())):
   p,q=map(int,input().split())
   if(q-p>1):
       s+=1
print(str(s))