s1=input()
s2=input()
i=0
left=''
right=''

i=s1.find('|')
left=left+s1[0:i]
right=right+s1[i+1:len(s1)]
dif=len(left)-len(right)
if len(s2)<abs(dif):
    print("Impossible")
else:
   if(dif>0):
       right=right+s2[0:abs(dif)]
   else:
       left =left +s2[0:abs(dif)]

   dif=abs(dif)

   if  (len(s2)-dif)%2:
       print("Impossible")
   else:
       index=(int)((len(s2)-dif)/2)
       left=left+s2[dif:dif+index]
       right=right+s2[dif+index
                      :len(s2)]
       result=''
       slash='|'
       result=left+slash+right
       print(result)
    




      
