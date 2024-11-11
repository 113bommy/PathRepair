x=input("")
tab=list(x)
entry=int(x)
aid=str()
if entry==0 :
  print("0")

elif entry<=9 :
  print("1")
elif 9<entry :
 for i in range(len(tab)) :
   tab[i]=int(tab[i])
 if 1<tab[0]:
     x=(2**len(tab))-1

 elif tab[0]==1:
    if 1<tab[1]:
          x=(2**len(tab))-1
    else:
          x=(2**(len(tab)-1))-1
          A=list()
          a=str()
          for i in range(len(tab)) :
               if i == 0 :
                A.append(1)
                a=str(A[i])
               else :
                A.append(0)
                a=a+str(A[i])

          number=int(a)
          b=str(number)
          b=int(b,2)

          while number<=entry :
             x=x+1
             alter=int(bin(b),2)+int(bin(1),2)
             help=bin(alter)
             aid=help[2:]

             s=str(aid)

             number=int(s)
             b=str(number)
             b=int(b,2)

 print(x)
