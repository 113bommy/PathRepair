

li=list(map(int,input().split()))



sm = sum(li)

mn=sm

for i in li:





    cnt=li.count(i)

    if cnt>=2:

         mn = min(sum(li)-min(cnt,3)*i, mn)
print(mn)


          

            
            

    
