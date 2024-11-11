z=int(input())
lst1=['zero','ten','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
lst2=['one','two','three','four','five','six','seven','eight','nine']
lst3=['eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
if z%10==0:
    print(lst1[z//10])
elif  20<z  :
    print(lst1[z//10]+'-'+lst2[(z%10)-1])
elif z<10:
    print(lst2[z-1])
else:
   print(lst3[(z%10)-1])    